#include "../../../include/commands/implementations/SynchronizeDirectoryCommand.h"

namespace cpp2 {

    SynchronizeDirectoryCommand::SynchronizeDirectoryCommand(ServerConnection &serverConnection, FileSystemManager &syncManager)
            : AbstractCommand(serverConnection, syncManager) {}

    bool SynchronizeDirectoryCommand::execute() {
        return false;
    }
}
