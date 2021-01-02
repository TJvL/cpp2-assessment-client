#ifndef CPP2CLIENT_DOWNLOADREMOTEFILECOMMAND_H
#define CPP2CLIENT_DOWNLOADREMOTEFILECOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class DownloadRemoteFileCommand : public AbstractCommand {
    public:
        explicit DownloadRemoteFileCommand(ServerConnection &serverConnection, FileSystemManager &syncManager);

        ~DownloadRemoteFileCommand() override = default;

        bool execute() override;
    };
}

#endif //CPP2CLIENT_DOWNLOADREMOTEFILECOMMAND_H
