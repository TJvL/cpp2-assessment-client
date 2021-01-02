#ifndef CPP2CLIENT_SERVERCONNECTION_H
#define CPP2CLIENT_SERVERCONNECTION_H

#include <string>
#include <asio/ip/tcp.hpp>

namespace cpp2 {
    class ServerConnection {
    public:
        ServerConnection(const std::string &host, const std::string &port);

        virtual ~ServerConnection();

        std::string waitForIncomingMessage();

        void sentOutgoingMessage(const std::string &message);

        std::istream &getIncomingStream();

        void pipeStreamTillEnd(std::istream &inputStream);

    private:
        asio::ip::tcp::iostream stream;
    };
}

#endif //CPP2CLIENT_SERVERCONNECTION_H
