#ifndef CPP2CLIENT_QUITCOMMAND_H
#define CPP2CLIENT_QUITCOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class QuitCommand : public AbstractCommand {
    public:
        bool execute(ServerConnection &serverConnection, FileSystemManager &fileSystemManager) override;
    };
}

#endif //CPP2CLIENT_QUITCOMMAND_H
