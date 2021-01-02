#include "../../../include/commands/implementations/QuitCommand.h"
#include "../../../include/Constants.h"

namespace cpp2 {

    QuitCommand::QuitCommand(ServerConnection &serverConnection, FileSystemManager &syncManager)
            : AbstractCommand(serverConnection, syncManager) {}

    bool QuitCommand::execute() {
        serverConnection.sentOutgoingMessage(QUIT_COMMAND);
        return false;
    }
}
