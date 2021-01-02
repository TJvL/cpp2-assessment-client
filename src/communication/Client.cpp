#include <iostream>
#include "../../include/communication/Client.h"
#include "../../include/Constants.h"
#include "../../include/ConsolePrintHelpers.h"

namespace cpp2 {
    Client::Client(const std::string& host, const std::string& port, const std::string& syncDirectoryName)
    : serverConnection(host, port), fileSystemManager(syncDirectoryName) {}

    void Client::handleUserCommands() {
        auto handlingCommands = true;
        while (handlingCommands) {
            try {
                auto commandName = commandSelector.waitForCommandInput();
                auto command = commandFactory.createCommand(commandName, serverConnection, fileSystemManager);
                handlingCommands = command->execute();
            } catch (const std::logic_error &error) {
                const auto message = error.what();
                std::cout << "error: " << message << NEW_LINE;
            }

            if (handlingCommands) {
                ConsolePrintHelpers::waitForEnterKey();
            }
        }
    }
}
