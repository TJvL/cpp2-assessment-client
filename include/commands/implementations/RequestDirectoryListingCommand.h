#ifndef CPP2CLIENT_REQUESTDIRECTORYLISTINGCOMMAND_H
#define CPP2CLIENT_REQUESTDIRECTORYLISTINGCOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class RequestDirectoryListingCommand : public AbstractCommand {
    public:
        bool execute(ServerConnection &serverConnection, FileSystemManager &fileSystemManager) override;
    };
}

#endif //CPP2CLIENT_REQUESTDIRECTORYLISTINGCOMMAND_H
