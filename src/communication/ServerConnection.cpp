#include <iostream>
#include "../../include/communication/ServerConnection.h"
#include "../../include/Constants.h"

namespace cpp2 {

    ServerConnection::ServerConnection(const std::string &host, const std::string &port)
            : stream(host, port) {
        if (!stream) {
            throw std::runtime_error("could not connect to server");
        } else {
            const auto message = waitForIncomingMessage();
            std::cout << ENTER_CHOICE_PROMPT << message << NEW_LINE;
        }
    }

    ServerConnection::~ServerConnection() {
        stream.close();
    }

    std::string ServerConnection::waitForIncomingMessage() {
        std::string message;
        getline(stream, message);

        if (stream.fail()) {
            throw std::runtime_error("connection interrupted");
        }

        message.erase(message.end() - 1); // remove '\r'

        return message;
    }

    void ServerConnection::sentOutgoingMessage(const std::string &message) {
        stream << message << RETURN_NEW_LINE;
    }

    std::istream& ServerConnection::getIncomingStream() {
        return stream;
    }

    void ServerConnection::pipeStreamTillEnd(const std::istream &inputStream) {
        stream << inputStream.rdbuf();
    }
}
