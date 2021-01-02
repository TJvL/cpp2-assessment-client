#include "../../../include/commands/implementations/RenameCommand.h"

namespace cpp2 {

    RenameCommand::RenameCommand(ServerConnection &serverConnection, FileSystemManager &syncManager)
            : AbstractCommand(serverConnection, syncManager) {}

    bool RenameCommand::execute() {
        return true;
    }
}
