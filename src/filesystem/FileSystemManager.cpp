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

    bool FileSystemManager::pathExists(const std::filesystem::path &relativePath) const {
        return std::filesystem::exists(rootSyncPath / relativePath);
    }

    bool FileSystemManager::refersToFile(const std::filesystem::path &relativePath) const {
        return std::filesystem::is_regular_file(rootSyncPath / relativePath);
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
        auto oldPath = rootSyncPath / relativePath;
        auto newPath = std::filesystem::path{oldPath}.replace_filename(newName);
        std::filesystem::rename(oldPath, newPath);
    }

    std::vector<FileInfo> FileSystemManager::listDirectoryInformation(const std::filesystem::path &relativePath) const {
        std::vector<FileInfo> listing;
        for(auto& entry : std::filesystem::directory_iterator(rootSyncPath / relativePath)) {
            auto fileName = entry.path().filename().c_str();
            auto fileSize = entry.file_size();
            auto fileType = getFileType(entry.status().type());
            listing.emplace_back(fileName, fileSize, 0, fileType);
        }

        return listing;
    }

    void FileSystemManager::writeFileFromStream(const std::filesystem::path &relativePath, std::istream &readStream,
                                                unsigned long readSize) const {
        std::ofstream writeStream{rootSyncPath / relativePath, std::ifstream::out | std::ifstream::binary};
        writeStream.exceptions(std::ifstream::badbit);

        std::copy_n(std::istreambuf_iterator<char>(readStream),
                    readSize,
                    std::ostreambuf_iterator<char>(writeStream));
    }

    std::unique_ptr<std::istream> FileSystemManager::openReadFileStream(const std::filesystem::path& relativePath) const {
        auto readStream = std::make_unique<std::ifstream>(rootSyncPath / relativePath, std::ifstream::in | std::ifstream::binary);
        readStream->exceptions(std::ifstream::badbit);
        return readStream;
    }
}
