#include <iostream>
#include "../../../include/commands/implementations/RequestDirectoryListingCommand.h"
#include "../../../include/Constants.h"
#include "../../../include/ConsolePrintHelpers.h"

namespace cpp2 {
    RequestDirectoryListingCommand::RequestDirectoryListingCommand(ServerConnection &serverConnection,
                                                                   FileSystemManager &fileSystemManager)
            : AbstractCommand(serverConnection, fileSystemManager) {}

    bool RequestDirectoryListingCommand::execute() {
        const auto relativePath = ConsolePrintHelpers::waitForPathInput();

        if (!fileSystemManager.pathExists(relativePath)) {
            throw std::logic_error{"no such directory present locally"};
        }

        serverConnection.sentOutgoingMessage(DIRECTORY_LIST_COMMAND);
        serverConnection.sentOutgoingMessage(relativePath);

        const auto response = serverConnection.waitForIncomingMessage();

        if (response == ERROR_NO_SUCH_DIRECTORY) {
            throw std::logic_error{"no such directory present remotely"};
        }

        const auto listingAmount = std::stoi(response);

        std::cout << "List of entries in server directory:" << NEW_LINE;
        for (auto a = 0; a < listingAmount; ++a) {
            std::cout << serverConnection.waitForIncomingMessage() << NEW_LINE;
        }

        // client is not shutting down after this execution
        return true;
    }
}
