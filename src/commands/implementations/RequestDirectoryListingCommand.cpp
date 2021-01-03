#include <iostream>
#include "../../../include/commands/implementations/RequestDirectoryListingCommand.h"
#include "../../../include/helpers/UserInterfaceHelpers.h"
#include "../../../include/helpers/ErrorCheckHelpers.h"

namespace cpp2 {
    RequestDirectoryListingCommand::RequestDirectoryListingCommand(ServerConnection &serverConnection,
                                                                   FileSystemManager &fileSystemManager)
            : AbstractCommand(serverConnection, fileSystemManager) {}

    bool RequestDirectoryListingCommand::execute() {
        const auto relativePath = UserInterfaceHelpers::waitForPathInput();

        if (!fileSystemManager.pathExists(relativePath)) {
            throw std::logic_error{"no such directory present locally"};
        }

        serverConnection.sentOutgoingMessage(DIRECTORY_LIST_COMMAND);
        serverConnection.sentOutgoingMessage(relativePath);

        const auto response = serverConnection.waitForIncomingMessage();

        if (response == ERROR_NO_SUCH_DIRECTORY) {
            throw std::logic_error{"no such directory present remotely"};
        }

        unsigned long listingAmount;
        try {
            listingAmount = std::stoul(response);
        } catch (const std::invalid_argument &error) {
            ErrorCheckHelpers::throwServerError(response);
        }

        if (listingAmount > 0) {
            for (auto a = 0; a < listingAmount; ++a) {
                std::cout << serverConnection.waitForIncomingMessage() << NEW_LINE;
            }
        } else {
            std::cout << "remote directory is empty" << NEW_LINE;
        }

        // client is not shutting down after this execution
        return true;
    }
}
