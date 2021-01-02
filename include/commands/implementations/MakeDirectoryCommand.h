#ifndef CPP2CLIENT_MAKEDIRECTORYCOMMAND_H
#define CPP2CLIENT_MAKEDIRECTORYCOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class MakeDirectoryCommand : public AbstractCommand {
    public:
        explicit MakeDirectoryCommand(ServerConnection &serverConnection, FileSystemManager &syncManager);

        ~MakeDirectoryCommand() override = default;

        bool execute() override;
    };
}

#endif //CPP2CLIENT_MAKEDIRECTORYCOMMAND_H
