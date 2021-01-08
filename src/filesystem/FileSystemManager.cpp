#include <fstream>
#include "../../include/filesystem/FileSystemManager.h"
#include "../../include/filesystem/FileTypeMapper.h"

namespace cpp2 {
    FileSystemManager::FileSystemManager(const std::string& syncDirectoryName)
            : rootSyncPath(std::filesystem::current_path() / syncDirectoryName) {
        if (!std::filesystem::exists(rootSyncPath)) {
            std::filesystem::create_directory(rootSyncPath);
        }
    }

    bool FileSystemManager::hasWritePermissions(const std::filesystem::path &relativePath) const {
        const auto status = std::filesystem::status(rootSyncPath / relativePath);
        return (status.permissions() & std::filesystem::perms::group_write) != std::filesystem::perms::none;
    }

    bool FileSystemManager::pathExists(const std::filesystem::path &relativePath) const {
        return std::filesystem::exists(rootSyncPath / relativePath);
    }

    bool FileSystemManager::refersToFile(const std::filesystem::path &relativePath) const {
        return std::filesystem::is_regular_file(rootSyncPath / relativePath);
    }

    bool FileSystemManager::refersToDirectory(const std::filesystem::path &relativePath) const {
        return std::filesystem::is_directory(rootSyncPath / relativePath);
    }

    unsigned long FileSystemManager::fileSize(const std::filesystem::path &relativePath) const {
        return std::filesystem::file_size(rootSyncPath / relativePath);
    }

    void FileSystemManager::makeDirectory(const std::filesystem::path& relativePath, const std::string &directoryName) const {
        std::filesystem::create_directory(rootSyncPath / relativePath / directoryName);
    }

    void FileSystemManager::deletePath(const std::filesystem::path& relativePath) const {
        std::filesystem::remove_all(rootSyncPath / relativePath);
    }

    void FileSystemManager::renamePath(const std::filesystem::path &relativePath, const std::string &newName) const {
        const auto oldPath = rootSyncPath / relativePath;
        const auto newPath = std::filesystem::path{oldPath}.replace_filename(newName);
        std::filesystem::rename(oldPath, newPath);
    }

    std::unique_ptr<std::unordered_map<std::string, FileInfo>> FileSystemManager::listDirectoryInformation(const std::filesystem::path &relativePath) const {
        auto listing = std::make_unique<std::unordered_map<std::string, FileInfo>>();
        for(auto& entry : std::filesystem::directory_iterator(rootSyncPath / relativePath)) {
            const auto fileName = entry.path().filename().c_str();
            const auto fileType = getFileType(entry.status().type());
            unsigned long fileSize{0};
            if (fileType == FILE) {
                fileSize = entry.file_size();
            }
            listing->emplace(fileName, std::move(FileInfo{fileName, fileSize, 0, fileType}));
        }

        return listing;
    }

    void FileSystemManager::writeFileFromStream(const std::filesystem::path &relativePath, std::istream &inputStream,
                                                const unsigned long readSize) const {
        std::ofstream writeStream{rootSyncPath / relativePath, std::ifstream::out | std::ifstream::binary};
        writeStream.exceptions(std::ifstream::badbit);

        std::copy_n(std::istreambuf_iterator<char>(inputStream),
                    readSize,
                    std::ostreambuf_iterator<char>(writeStream));

        inputStream.ignore(1);

        writeStream.close();
    }

    std::unique_ptr<const std::istream> FileSystemManager::openReadFileStream(const std::filesystem::path& relativePath) const {
        auto readStream = std::make_unique<std::ifstream>(rootSyncPath / relativePath, std::ifstream::in | std::ifstream::binary);
        readStream->exceptions(std::ifstream::badbit);
        return readStream;
    }
}
