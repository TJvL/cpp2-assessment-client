#ifndef CPP2CLIENT_SYNCHRONIZEDIRECTORYCOMMAND_H
#define CPP2CLIENT_SYNCHRONIZEDIRECTORYCOMMAND_H

#include "../AbstractCommand.h"

namespace cpp2 {
    class SynchronizeDirectoryCommand : public AbstractCommand {
    public:
        bool execute(ServerConnection &serverConnection, const FileSystemManager &fileSystemManager) const override;

    private:
        static void syncDirectory(const std::filesystem::path& currentDirectoryPath, ServerConnection &serverConnection, const FileSystemManager &fileSystemManager);
        static std::unique_ptr<std::unordered_map<std::string, FileInfo>>
        retrieveRemoteDirectoryListing(const std::filesystem::path& remoteDirectoryPath, ServerConnection &serverConnection);
        static void uploadFile(const std::filesystem::path &path, ServerConnection &serverConnection, const FileSystemManager &fileSystemManager);
    };
}

#endif //CPP2CLIENT_SYNCHRONIZEDIRECTORYCOMMAND_H
