#include "../../../include/commands/implementations/DownloadRemoteFileCommand.h"
#include "../../../include/helpers/UserInterfaceHelpers.h"
#include "../../../include/helpers/ErrorCheckHelpers.h"

namespace cpp2 {
bool DownloadRemoteFileCommand::execute(ServerConnection &serverConnection, const FileSystemManager &fileSystemManager) const {
        const auto relativePath = UserInterfaceHelpers::waitForPathInput();

        if (!fileSystemManager.pathExists(relativePath)) {
            throw std::logic_error{"no such directory present locally"};
        }

        if (!fileSystemManager.refersToFile(relativePath)) {
            throw std::logic_error{"path does not refer to a local file"};
        }

        serverConnection.sentOutgoingMessage(GET_COMMAND);
        serverConnection.sentOutgoingMessage(relativePath);

        const auto response = serverConnection.waitForIncomingMessage();

        unsigned long fileSize;
        try {
            fileSize = std::stoul(response);
        } catch (const std::invalid_argument &error) {
            ErrorCheckHelpers::throwServerError(response);
        }

        auto &inputStream = serverConnection.getIncomingStream();
        fileSystemManager.writeFileFromStream(relativePath, inputStream, fileSize);

        std::cout << "remote file downloaded" << NEW_LINE;

        return true;
    }
}
