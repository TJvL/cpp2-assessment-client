#ifndef CPP2CLIENT_SYNCHRONIZEDIRECTORYCOMMAND_H
#define CPP2CLIENT_SYNCHRONIZEDIRECTORYCOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class SynchronizeDirectoryCommand : public AbstractCommand {
    public:
        bool execute(ServerConnection &serverConnection, FileSystemManager &fileSystemManager) override;
    };
}

#endif //CPP2CLIENT_SYNCHRONIZEDIRECTORYCOMMAND_H
