#include "../../../include/commands/implementations/RenameCommand.h"
#include "../../../include/helpers/UserInterfaceHelpers.h"
#include "../../../include/helpers/ErrorCheckHelpers.h"

namespace cpp2 {

    RenameCommand::RenameCommand(ServerConnection &serverConnection, FileSystemManager &syncManager)
            : AbstractCommand(serverConnection, syncManager) {}

    bool RenameCommand::execute() {
        const auto relativePath = UserInterfaceHelpers::waitForPathInput();

        if (!fileSystemManager.pathExists(relativePath)) {
            throw std::logic_error{"no such directory or file present locally"};
        }

        const auto newName = UserInterfaceHelpers::waitForDirectoryNameInput();

        serverConnection.sentOutgoingMessage(RENAME_COMMAND);
        serverConnection.sentOutgoingMessage(relativePath);
        serverConnection.sentOutgoingMessage(newName);
        const auto response = serverConnection.waitForIncomingMessage();

        if (response != OK_RESPONSE) {
            ErrorCheckHelpers::throwServerError(response);
        }

        fileSystemManager.renamePath(relativePath, newName);

        return true;
    }
}
