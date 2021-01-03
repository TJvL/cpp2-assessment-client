#include "../../../include/commands/implementations/MakeDirectoryCommand.h"
#include "../../../include/helpers/UserInterfaceHelpers.h"
#include "../../../include/helpers/ErrorCheckHelpers.h"

namespace cpp2 {

    MakeDirectoryCommand::MakeDirectoryCommand(ServerConnection &serverConnection, FileSystemManager &syncManager)
            : AbstractCommand(serverConnection, syncManager) {}

    bool MakeDirectoryCommand::execute() {
        const auto relativePath = UserInterfaceHelpers::waitForPathInput();

        if (!fileSystemManager.pathExists(relativePath)) {
            throw std::logic_error{"no such directory present locally"};
        }

        if (!fileSystemManager.refersToDirectory(relativePath)) {
            throw std::logic_error{"path does not refer to a local directory"};
        }

        const auto directoryName = UserInterfaceHelpers::waitForDirectoryNameInput();

        serverConnection.sentOutgoingMessage(MAKE_DIRECTORY_COMMAND);
        serverConnection.sentOutgoingMessage(relativePath);
        serverConnection.sentOutgoingMessage(directoryName);
        const auto response = serverConnection.waitForIncomingMessage();

        if (response != OK_RESPONSE) {
            ErrorCheckHelpers::throwServerError(response);
        }

        fileSystemManager.makeDirectory(relativePath, directoryName);

        std::cout << "directory created" << NEW_LINE;

        return true;
    }
}
