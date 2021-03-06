#ifndef CPP2CLIENT_DOWNLOADREMOTEFILECOMMAND_H
#define CPP2CLIENT_DOWNLOADREMOTEFILECOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class DownloadRemoteFileCommand : public AbstractCommand {
    public:
        bool execute(ServerConnection &serverConnection, const FileSystemManager &fileSystemManager) const override;
    };
}

#endif //CPP2CLIENT_DOWNLOADREMOTEFILECOMMAND_H
