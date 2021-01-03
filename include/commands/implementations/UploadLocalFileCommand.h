#ifndef CPP2CLIENT_UPLOADLOCALFILECOMMAND_H
#define CPP2CLIENT_UPLOADLOCALFILECOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class UploadLocalFileCommand : public AbstractCommand {
    public:
        explicit UploadLocalFileCommand(ServerConnection &serverConnection, FileSystemManager &syncManager);

        ~UploadLocalFileCommand() override = default;

        bool execute() override;
    };
}

#endif //CPP2CLIENT_UPLOADLOCALFILECOMMAND_H
