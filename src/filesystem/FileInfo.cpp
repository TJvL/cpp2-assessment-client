#include <ctime>
#include <vector>
#include <iostream>
#include <iomanip>
#include "../../include/filesystem/FileInfo.h"

namespace cpp2 {

    FileInfo::FileInfo(std::string fileName, const unsigned long fileSize, const std::time_t lastModified, const FileType fileType)
            : fileName(std::move(fileName)), fileSize(fileSize), fileType(fileType), lastModified(lastModified) {}

    FileInfo::FileInfo(const std::string &listString) {
        const auto delimiter = '|';

        std::vector<std::string> splitList;
        size_t last = 0, next;
        while ((next = listString.find(delimiter, last)) != std::string::npos) {
            splitList.push_back(std::move(listString.substr(last, next - last)));
            last = next + 1;
        }
        splitList.push_back(std::move(listString.substr(last)));

        fileType = getFileTypeFromCharacter(splitList[0][0]);
        fileName = splitList[1];
        std::istringstream stringStream{splitList[2]};
        struct std::tm tm{};
        stringStream >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
        lastModified = mktime(&tm);
        fileSize = std::stoul(splitList[3]);
    }

    std::string FileInfo::toString() const {
        std::vector<char> buffer(20);
        std::strftime(buffer.data(), 20, "%Y-%m-%d %H:%M:%S", std::localtime(&lastModified));
        std::ostringstream stringStream;
        stringStream << getFileTypeCharacter() << '|'
                     << fileName << '|'
                     << buffer.data() << '|'
                     << fileSize;
        return stringStream.str();
    }

    char FileInfo::getFileTypeCharacter() const {
        switch (fileType) {
            case FILE:
                return 'F';
            case DIRECTORY:
                return 'D';
            case OTHER:
            default:
                return '*';
        }
    }

    FileType FileInfo::getFileTypeFromCharacter(char c) {
        if (c == 'F') return FILE;
        if (c == 'D') return DIRECTORY;
        return OTHER;
    }

    std::string FileInfo::getFileName() const {
        return fileName;
    }

    unsigned long FileInfo::getFileSize() const {
        return fileSize;
    }

    FileType FileInfo::getFileType() const {
        return fileType;
    }

    std::time_t FileInfo::getLastModified() const {
        return lastModified;
    }
}
