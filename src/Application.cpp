#include <iostream>
#include "../include/Application.h"
#include "../include/Constants.h"

namespace cpp2 {
    Application::Application(const std::string &host, const std::string &port, const std::string &syncDirectoryName)
            : client(host, port, syncDirectoryName) {}

    int Application::run() {
        auto result = EXIT_SUCCESS;
        try {
            client.handleUserCommands();
        } catch (const std::exception &exception) {
            std::cout << "fatal error: " << exception.what() << NEW_LINE;
            result = EXIT_FAILURE;
        }
        return result;
    }
}
