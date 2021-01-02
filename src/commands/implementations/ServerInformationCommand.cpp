#include <iostream>
#include "../../../include/commands/implementations/ServerInformationCommand.h"
#include "../../../include/Constants.h"

namespace cpp2 {
    ServerInformationCommand::ServerInformationCommand(ServerConnection &serverConnection, FileSystemManager &syncManager)
            : AbstractCommand(serverConnection, syncManager) {}

    bool ServerInformationCommand::execute() {
        serverConnection.sentOutgoingMessage(INFO_COMMAND);
        auto response = serverConnection.waitForIncomingMessage();
        std::cout << response << NEW_LINE;
        return true;
    }
}
