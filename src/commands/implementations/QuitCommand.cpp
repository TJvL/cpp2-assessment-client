#include "../../../include/commands/implementations/QuitCommand.h"
#include "../../../include/Constants.h"

namespace cpp2 {
    bool QuitCommand::execute(ServerConnection &serverConnection, const FileSystemManager &fileSystemManager) const {
        serverConnection.sentOutgoingMessage(QUIT_COMMAND);
        return false;
    }
}
