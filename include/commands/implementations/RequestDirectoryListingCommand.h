#ifndef CPP2CLIENT_REQUESTDIRECTORYLISTINGCOMMAND_H
#define CPP2CLIENT_REQUESTDIRECTORYLISTINGCOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class RequestDirectoryListingCommand : public AbstractCommand {
    public:
        explicit RequestDirectoryListingCommand(ServerConnection &serverConnection, FileSystemManager &fileSystemManager);

        ~RequestDirectoryListingCommand() override = default;

        bool execute() override;
    };
}

#endif //CPP2CLIENT_REQUESTDIRECTORYLISTINGCOMMAND_H