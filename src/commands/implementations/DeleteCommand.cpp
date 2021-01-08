#include "../../../include/commands/implementations/DeleteCommand.h"
#include "../../../include/helpers/UserInterfaceHelpers.h"
#include "../../../include/helpers/ErrorCheckHelpers.h"

namespace cpp2 {
    bool DeleteCommand::execute(ServerConnection &serverConnection, const FileSystemManager &fileSystemManager) const {
        const auto relativePath = UserInterfaceHelpers::waitForPathInput();

        if (relativePath.empty()) {
            throw std::logic_error{"can't delete root"};
        }

        if (!fileSystemManager.pathExists(relativePath)) {
            throw std::logic_error{"no such path present locally"};
        }

        serverConnection.sentOutgoingMessage(DELETE_COMMAND);
        serverConnection.sentOutgoingMessage(relativePath);
        const auto response = serverConnection.waitForIncomingMessage();

        if (response != OK_RESPONSE) {
            ErrorCheckHelpers::throwServerError(response);
        }

        fileSystemManager.deletePath(relativePath);

        std::cout << "path deleted" << NEW_LINE;

        return true;
    }
}
