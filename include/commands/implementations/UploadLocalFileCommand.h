#ifndef CPP2CLIENT_UPLOADLOCALFILECOMMAND_H
#define CPP2CLIENT_UPLOADLOCALFILECOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class UploadLocalFileCommand : public AbstractCommand {
    public:
        bool execute(ServerConnection &serverConnection, FileSystemManager &syncManager) override;
    };
}

#endif //CPP2CLIENT_UPLOADLOCALFILECOMMAND_H
