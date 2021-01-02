#ifndef CPP2CLIENT_SYNCHRONIZEDIRECTORYCOMMAND_H
#define CPP2CLIENT_SYNCHRONIZEDIRECTORYCOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class SynchronizeDirectoryCommand : public AbstractCommand {
    public:
        explicit SynchronizeDirectoryCommand(ServerConnection &serverConnection, FileSystemManager &syncManager);

        ~SynchronizeDirectoryCommand() override = default;

        bool execute() override;
    };
}

#endif //CPP2CLIENT_SYNCHRONIZEDIRECTORYCOMMAND_H
