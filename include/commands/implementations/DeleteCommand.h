#ifndef CPP2CLIENT_DELETECOMMAND_H
#define CPP2CLIENT_DELETECOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class DeleteCommand : public AbstractCommand  {
    public:
        explicit DeleteCommand(ServerConnection &serverConnection, FileSystemManager &syncManager);

        ~DeleteCommand() override = default;

        bool execute() override;
    };
}

#endif //CPP2CLIENT_DELETECOMMAND_H
