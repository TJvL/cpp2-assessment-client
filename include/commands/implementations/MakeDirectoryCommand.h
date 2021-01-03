#ifndef CPP2CLIENT_MAKEDIRECTORYCOMMAND_H
#define CPP2CLIENT_MAKEDIRECTORYCOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class MakeDirectoryCommand : public AbstractCommand {
    public:
        bool execute(ServerConnection &serverConnection, FileSystemManager &fileSystemManager) override;
    };
}

#endif //CPP2CLIENT_MAKEDIRECTORYCOMMAND_H
