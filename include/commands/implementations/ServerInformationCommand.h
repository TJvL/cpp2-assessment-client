#ifndef CPP2CLIENT_SERVERINFORMATIONCOMMAND_H
#define CPP2CLIENT_SERVERINFORMATIONCOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class ServerInformationCommand : public AbstractCommand {
    public:
        bool execute(ServerConnection &serverConnection, const FileSystemManager &syncManager) const override;
    };
}

#endif //CPP2CLIENT_SERVERINFORMATIONCOMMAND_H
