#ifndef CPP2CLIENT_FILEINFO_H
#define CPP2CLIENT_FILEINFO_H

#include "FileType.h"

namespace cpp2 {
    class FileInfo {
    public:
        FileInfo(std::string fileName, const unsigned long fileSize, const std::time_t lastModified,
                 const FileType fileType);

        FileInfo(const std::string &listString);

        std::string toString() const;

        char getFileTypeCharacter() const;

        static FileType getFileTypeFromCharacter(char c);

        std::string getFileName() const;

        unsigned long getFileSize() const;

        FileType getFileType() const;

        std::time_t getLastModified() const;

    private:
        std::string fileName;
        unsigned long fileSize;
        FileType fileType;
        std::time_t lastModified;
    };
}

#endif //CPP2CLIENT_FILEINFO_H
