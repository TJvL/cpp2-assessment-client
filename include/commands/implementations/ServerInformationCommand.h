#ifndef CPP2CLIENT_SERVERINFORMATIONCOMMAND_H
#define CPP2CLIENT_SERVERINFORMATIONCOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class ServerInformationCommand : public AbstractCommand {
    public:
        explicit ServerInformationCommand(ServerConnection &serverConnection, FileSystemManager &syncManager);

        ~ServerInformationCommand() override = default;

        bool execute() override;
    };
}

#endif //CPP2CLIENT_SERVERINFORMATIONCOMMAND_H
