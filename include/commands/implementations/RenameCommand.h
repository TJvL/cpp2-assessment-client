#ifndef CPP2CLIENT_RENAMECOMMAND_H
#define CPP2CLIENT_RENAMECOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class RenameCommand : public AbstractCommand {
    public:
        bool execute(ServerConnection &serverConnection, const FileSystemManager &fileSystemManager) const override;
    };
}

#endif //CPP2CLIENT_RENAMECOMMAND_H
