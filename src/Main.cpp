#include <iostream>
#include "../include/Application.h"

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

    cpp2::Application application{host, port, syncDirectoryName};
    return application.run();
}
