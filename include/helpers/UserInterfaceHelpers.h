#ifndef CPP2CLIENT_USERINTERFACEHELPERS_H
#define CPP2CLIENT_USERINTERFACEHELPERS_H

#include <filesystem>
#include <iostream>
#include "../Constants.h"

namespace cpp2 {
    class UserInterfaceHelpers {
    public:
        static void printCommandOptions();

        static void waitForEnterKey();

        static std::string waitForDirectoryNameInput();

        static std::filesystem::path waitForPathInput();

    private:
        UserInterfaceHelpers() = default;
    };
}

#endif //CPP2CLIENT_USERINTERFACEHELPERS_H
