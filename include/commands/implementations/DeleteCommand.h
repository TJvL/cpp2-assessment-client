#ifndef CPP2CLIENT_DELETECOMMAND_H
#define CPP2CLIENT_DELETECOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class DeleteCommand : public AbstractCommand  {
    public:
        bool execute(ServerConnection &serverConnection, const FileSystemManager &fileSystemManager) const override;
    };
}

#endif //CPP2CLIENT_DELETECOMMAND_H
