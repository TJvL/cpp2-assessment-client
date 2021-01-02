#ifndef CPP2CLIENT_QUITCOMMAND_H
#define CPP2CLIENT_QUITCOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class QuitCommand : public AbstractCommand {
    public:
        explicit QuitCommand(ServerConnection &serverConnection, FileSystemManager &syncManager);

        ~QuitCommand() override = default;

        bool execute() override;
    };
}

#endif //CPP2CLIENT_QUITCOMMAND_H
