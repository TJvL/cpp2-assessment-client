#ifndef CPP2CLIENT_FILESYSTEMMANAGER_H
#define CPP2CLIENT_FILESYSTEMMANAGER_H

#include <filesystem>
#include <vector>
#include <unordered_map>
#include "../../include/filesystem/FileInfo.h"

namespace cpp2 {
    class FileSystemManager {
    public:
        FileSystemManager(const std::string &syncDirectoryName = "sync");

        bool hasWritePermissions(const std::filesystem::path &relativePath) const;

        bool pathExists(const std::filesystem::path &relativePath) const;

        bool refersToFile(const std::filesystem::path &relativePath) const;

        bool refersToDirectory(const std::filesystem::path &relativePath) const;

        unsigned long fileSize(const std::filesystem::path &relativePath) const;

        void makeDirectory(const std::filesystem::path &relativePath, const std::string &directoryName) const;

        void deletePath(const std::filesystem::path &relativePath) const;

        void renamePath(const std::filesystem::path &relativePath, const std::string& newName) const;

        std::unique_ptr<std::unordered_map<std::string, FileInfo>> listDirectoryInformation(const std::filesystem::path &relativePath) const;

        void writeFileFromStream(const std::filesystem::path &relativePath, std::istream &inputStream,
                                 const unsigned long readSize) const;

        std::unique_ptr<const std::istream> openReadFileStream(const std::filesystem::path &relativePath) const;

    private:
        const std::filesystem::path rootSyncPath;
    };
}

#endif //CPP2CLIENT_FILESYSTEMMANAGER_H
