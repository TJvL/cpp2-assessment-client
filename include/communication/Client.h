#ifndef CPP2CLIENT_CLIENT_H
#define CPP2CLIENT_CLIENT_H

#include "ServerConnection.h"
#include "../commands/CommandFactory.h"
#include "../commands/CommandSelector.h"

namespace cpp2 {
    class Client {
    public:
        Client(const std::string& host, const std::string& port, const std::string& syncDirectoryName);

        void handleUserCommands();
    private:
        CommandSelector commandSelector;
        ServerConnection serverConnection;
        FileSystemManager fileSystemManager;
        CommandFactory commandFactory;
    };
}

#endif //CPP2CLIENT_CLIENT_H
