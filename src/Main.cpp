#include <iostream>
#include "../include/Application.h"
#include "../include/Constants.h"

int main(int argc, char *argv[]) {
    std::string port = "5000";
    std::string host = "localhost";
    std::string syncDirectoryName{"sync"};

    if (argc >= 2) {
        port = argv[1];
    }

    if (argc >= 3) {
        host = argv[2];
    }

    if (argc >= 4) {
        syncDirectoryName = argv[3];
    }

    try {
        cpp2::Application application{host, port, syncDirectoryName};
        return application.run();
    } catch (const std::exception &error) {
        std::cout << error.what() << NEW_LINE;
        return EXIT_FAILURE;
    }
}
