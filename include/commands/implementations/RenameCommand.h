#ifndef CPP2CLIENT_RENAMECOMMAND_H
#define CPP2CLIENT_RENAMECOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class RenameCommand : public AbstractCommand {
    public:
        explicit RenameCommand(ServerConnection &serverConnection, FileSystemManager &syncManager);

        ~RenameCommand() override = default;

        bool execute() override;
    };
}

#endif //CPP2CLIENT_RENAMECOMMAND_H
