#ifndef CPP2CLIENT_APPLICATION_H
#define CPP2CLIENT_APPLICATION_H

#include <string>
#include "communication/Client.h"
#include "filesystem/FileSystemManager.h"

namespace cpp2 {
    class Application {
    public:
        Application(const std::string &host, const std::string &port, const std::string &syncDirectoryName);

        int run();

    private:
        Client client;
    };
}

#endif //CPP2CLIENT_APPLICATION_H
