#include "../../../include/commands/implementations/DeleteCommand.h"
#include "../../../include/Constants.h"

namespace cpp2 {
    DeleteCommand::DeleteCommand(ServerConnection &serverConnection, FileSystemManager &syncManager)
            : AbstractCommand(serverConnection, syncManager) {}

    bool DeleteCommand::execute() {
        return true;
    }
}
