#include <iostream>
#include "../../../include/commands/implementations/UploadLocalFileCommand.h"
#include "../../../include/helpers/UserInterfaceHelpers.h"
#include "../../../include/helpers/ErrorCheckHelpers.h"

namespace cpp2 {

    UploadLocalFileCommand::UploadLocalFileCommand(ServerConnection &serverConnection, FileSystemManager &syncManager)
            : AbstractCommand(serverConnection, syncManager) {}

    bool UploadLocalFileCommand::execute() {
        const auto relativePath = UserInterfaceHelpers::waitForPathInput();

        if (!fileSystemManager.pathExists(relativePath)) {
            throw std::logic_error{"no such directory present locally"};
        }

        if (!fileSystemManager.refersToFile(relativePath)) {
            throw std::logic_error{"path does not refer to a local file"};
        }

        const auto fileSize = fileSystemManager.fileSize(relativePath);

        const auto fileStream = fileSystemManager.openReadFileStream(relativePath);

        serverConnection.sentOutgoingMessage(PUT_COMMAND);
        serverConnection.sentOutgoingMessage(relativePath);
        serverConnection.sentOutgoingMessage(std::to_string(fileSize));

        const auto response = serverConnection.waitForIncomingMessage();

        if (response != OK_RESPONSE) {
            ErrorCheckHelpers::throwServerError(response);
        }

        serverConnection.pipeStreamTillEnd(*fileStream);

        std::cout << "local file uploaded" << NEW_LINE;

        // client is not shutting down after this execution
        return true;
    }
}
