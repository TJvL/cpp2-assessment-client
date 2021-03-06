#include <iostream>
#include "../../../include/commands/implementations/ServerInformationCommand.h"
#include "../../../include/Constants.h"

namespace cpp2 {

    bool ServerInformationCommand::execute(ServerConnection &serverConnection, const FileSystemManager &fileSystemManager) const {
        serverConnection.sentOutgoingMessage(INFO_COMMAND);
        auto response = serverConnection.waitForIncomingMessage();
        std::cout << response << NEW_LINE;
        return true;
    }
}
