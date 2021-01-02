#include "../../../include/commands/implementations/MakeDirectoryCommand.h"
#include "../../../include/Constants.h"

namespace cpp2 {

    MakeDirectoryCommand::MakeDirectoryCommand(ServerConnection &serverConnection, FileSystemManager &syncManager)
            : AbstractCommand(serverConnection, syncManager) {}

    bool MakeDirectoryCommand::execute() {
        return true;
    }
}
