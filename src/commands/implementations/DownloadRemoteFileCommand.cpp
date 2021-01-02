#include "../../../include/commands/implementations/DownloadRemoteFileCommand.h"
#include "../../../include/ConsolePrintHelpers.h"

namespace cpp2 {
    DownloadRemoteFileCommand::DownloadRemoteFileCommand(ServerConnection &serverConnection, FileSystemManager &syncManager)
            : AbstractCommand(serverConnection, syncManager) {}

    bool DownloadRemoteFileCommand::execute() {
        const auto relativePath = ConsolePrintHelpers::waitForPathInput();

        if (!fileSystemManager.pathExists(relativePath)) {
            throw std::logic_error{"no such directory present locally"};
        }

        if (!fileSystemManager.refersToFile(relativePath)) {
            throw std::logic_error{"path does not refer to a local file"};
        }

        serverConnection.sentOutgoingMessage(GET_COMMAND);
        serverConnection.sentOutgoingMessage(relativePath);

        const auto response = serverConnection.waitForIncomingMessage();

        if (response == ERROR_NO_SUCH_FILE) {
            throw std::logic_error{"no such file present remotely"};
        } else if (response == ERROR_NO_PERMISSION) {
            throw std::logic_error{"no permission remotely"};
        }

        unsigned long fileSize;
        try {
            fileSize = std::stoul(response);
        } catch (std::invalid_argument &error) {
            throw std::logic_error{"unknown server response aborting command"};
        }

        auto &inputStream = serverConnection.getIncomingStream();
        fileSystemManager.writeFileFromStream(relativePath, inputStream, fileSize);

        std::cout << "remote file downloaded" << NEW_LINE;

        return true;
    }
}
