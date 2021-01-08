#ifndef CPP2CLIENT_SERVERCONNECTION_H
#define CPP2CLIENT_SERVERCONNECTION_H

#include <string>
#include <asio/ip/tcp.hpp>

namespace cpp2 {
    class ServerConnection {
    public:
        ServerConnection(const std::string &host, const std::string &port);

        ~ServerConnection();

        ServerConnection(const ServerConnection &other) = delete;

        ServerConnection(ServerConnection &&other) = delete;

        ServerConnection &operator=(const ServerConnection &other) = delete;

        ServerConnection &operator=(ServerConnection &&other) = delete;

        std::string waitForIncomingMessage();

        void sentOutgoingMessage(const std::string &message);

        std::istream &getIncomingStream();

        void pipeStreamTillEnd(const std::istream &inputStream);

    private:
        asio::ip::tcp::iostream stream;
    };
}

#endif //CPP2CLIENT_SERVERCONNECTION_H
