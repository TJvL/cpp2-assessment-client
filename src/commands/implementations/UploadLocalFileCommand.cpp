#include <iostream>
#include "../../../include/commands/implementations/UploadLocalFileCommand.h"
#include "../../../include/ConsolePrintHelpers.h"

namespace cpp2 {

    UploadLocalFileCommand::UploadLocalFileCommand(ServerConnection &serverConnection, FileSystemManager &syncManager)
            : AbstractCommand(serverConnection, syncManager) {}

    bool UploadLocalFileCommand::execute() {
        const auto relativePath = ConsolePrintHelpers::waitForPathInput();

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
        // check if the response was an 'OK' else throw error
        throwIfErrorResponse(response);

        serverConnection.pipeStreamTillEnd(*fileStream);

        std::cout << "local file uploaded" << NEW_LINE;

        // client is not shutting down after this execution
        return true;
    }

    void UploadLocalFileCommand::throwIfErrorResponse(const std::string& response) {
        if (response != OK_RESPONSE) {
            if (response == ERROR_NO_SUCH_DIRECTORY) {
                throw std::logic_error{"no such directory present remotely"};
            } else if (response == ERROR_NOT_ENOUGH_DISK_SPACE) {
                throw std::logic_error{"not enough disk space available remotely"};
            } else if (response == ERROR_NO_PERMISSION) {
                throw std::logic_error{"no permission remotely"};
            } else {
                throw std::logic_error{"unknown server response aborting command"};
            }
        }
    }
}
