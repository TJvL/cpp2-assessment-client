#include <unordered_map>
#include "../../../include/commands/implementations/SynchronizeDirectoryCommand.h"
#include "../../../include/helpers/UserInterfaceHelpers.h"
#include "../../../include/helpers/ErrorCheckHelpers.h"

namespace cpp2 {

    bool SynchronizeDirectoryCommand::execute(ServerConnection &serverConnection,
                                              const FileSystemManager &fileSystemManager) const {
        // get user input on directory to synchronize
        const auto relativePath = UserInterfaceHelpers::waitForPathInput();

        syncDirectory(relativePath, serverConnection, fileSystemManager);

        return true;
    }

    void SynchronizeDirectoryCommand::syncDirectory(const std::filesystem::path &currentDirectoryPath,
                                                    ServerConnection &serverConnection,
                                                    const FileSystemManager &fileSystemManager) {

        std::cout << "synchronising local directory: " << currentDirectoryPath << NEW_LINE;

        if (!fileSystemManager.pathExists(currentDirectoryPath)) {
            throw std::logic_error{"no such directory present locally"};
        }

        if (!fileSystemManager.refersToDirectory(currentDirectoryPath)) {
            throw std::logic_error{"path does not refer to a local directory"};
        }

        const auto localDirectory = fileSystemManager.listDirectoryInformation(currentDirectoryPath);
        const auto remoteDirectory = retrieveRemoteDirectoryListing(currentDirectoryPath, serverConnection);

        for (const auto&[localFileName, localFileInfo] : *localDirectory) {
            if (localFileInfo.getFileType() == FILE) {

                if (remoteDirectory->contains(localFileName)) {

                    // check if file on server is newer or equally old
                    const auto &remoteFileInfo = remoteDirectory->at(localFileName);
                    if (remoteFileInfo.getLastModified() >= localFileInfo.getLastModified()) {
                        std::cout << "skipping upload of local file: " << localFileName << NEW_LINE;
                        continue; // skip upload of the file
                    }
                }

                const auto localFilePath = currentDirectoryPath / localFileName;

                std::cout << "uploading local file: " << localFileName << NEW_LINE;
                uploadFile(localFilePath, serverConnection, fileSystemManager);

            } else if (localFileInfo.getFileType() == DIRECTORY) {

                // recursive call into sub directory
                syncDirectory(currentDirectoryPath / localFileName, serverConnection, fileSystemManager);
            }
        }

        // check if any files on server are left that are not present locally
        for (const auto&[remoteFileName, remoteFileInfo] : *remoteDirectory) {
            if (!localDirectory->contains(remoteFileName)) {

                std::cout << "deleting remote file: " << remoteFileName << NEW_LINE;

                serverConnection.sentOutgoingMessage(DELETE_COMMAND);
                serverConnection.sentOutgoingMessage(currentDirectoryPath / remoteFileName);
                const auto delResponse = serverConnection.waitForIncomingMessage();

                if (delResponse != OK_RESPONSE) {
                    ErrorCheckHelpers::throwServerError(delResponse);
                }
            }
        }
    }

    void SynchronizeDirectoryCommand::uploadFile(const std::filesystem::path &path, ServerConnection &serverConnection,
                                                 const FileSystemManager &fileSystemManager) {
        // upload file to server
        const auto fileSize = fileSystemManager.fileSize(path);
        const auto fileStream = fileSystemManager.openReadFileStream(path);

        serverConnection.sentOutgoingMessage(PUT_COMMAND);
        serverConnection.sentOutgoingMessage(path);
        serverConnection.sentOutgoingMessage(std::to_string(fileSize));

        const auto putResponse = serverConnection.waitForIncomingMessage();

        if (putResponse != OK_RESPONSE) {
            ErrorCheckHelpers::throwServerError(putResponse);
        }

        serverConnection.pipeStreamTillEnd(*fileStream);
    }

    std::unique_ptr<std::unordered_map<std::string, FileInfo>>
    SynchronizeDirectoryCommand::retrieveRemoteDirectoryListing(const std::filesystem::path &remoteDirectoryPath,
                                                                ServerConnection &serverConnection) {
        auto remoteDirectory = std::make_unique<std::unordered_map<std::string, FileInfo>>();

        // sent DIR command
        serverConnection.sentOutgoingMessage(DIRECTORY_LIST_COMMAND);
        serverConnection.sentOutgoingMessage(remoteDirectoryPath);

        // wait for directory list entries amount
        const auto dirResponse = serverConnection.waitForIncomingMessage();

        if (dirResponse == ERROR_NO_SUCH_DIRECTORY) {
            // create directory on server
            const auto newDirectoryName = remoteDirectoryPath.filename().c_str();
            const auto newDirectoryRootPath = std::filesystem::path{remoteDirectoryPath}.remove_filename();

            serverConnection.sentOutgoingMessage(MAKE_DIRECTORY_COMMAND);
            serverConnection.sentOutgoingMessage(newDirectoryRootPath);
            serverConnection.sentOutgoingMessage(newDirectoryName);
            const auto makeDirResponse = serverConnection.waitForIncomingMessage();

            if (makeDirResponse != OK_RESPONSE) {
                ErrorCheckHelpers::throwServerError(makeDirResponse);
            }
        } else {
            unsigned long listingAmount;
            try {
                listingAmount = std::stoul(dirResponse);
            } catch (const std::invalid_argument &error) {
                throw std::runtime_error{
                        "sync dir: received invalid response while parsing remote directory listing amount"};
            }

            // parse remote directory information
            for (auto a = 0; a < listingAmount; ++a) {
                FileInfo info(serverConnection.waitForIncomingMessage());
                remoteDirectory->emplace(info.getFileName(), info);
            }
        }

        return remoteDirectory;
    }
}
