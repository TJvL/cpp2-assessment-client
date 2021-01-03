#include <iostream>
#include "../../include/commands/CommandSelector.h"
#include "../../include/Constants.h"
#include "../../include/helpers/UserInterfaceHelpers.h"

namespace cpp2 {
    CommandSelector::CommandSelector()
            : commandMap({
                                 {"1", CommandName::SERVER_INFORMATION},
                                 {"2", CommandName::REQUEST_DIRECTORY_LISTING},
                                 {"3", CommandName::DOWNLOAD_REMOTE_FILE},
                                 {"4", CommandName::UPLOAD_LOCAL_FILE},
                                 {"5", CommandName::RENAME},
                                 {"6", CommandName::DELETE},
                                 {"7", CommandName::MAKE_DIRECTORY},
                                 {"8", CommandName::SYNC_DIRECTORY},
                                 {"9", CommandName::QUIT}
                         }) {}

    CommandName CommandSelector::waitForCommandInput() const {
        CommandName command;
        auto choosing = true;
        while (choosing) {
            UserInterfaceHelpers::printCommandOptions();
            std::string input;
            std::cin >> input;
            std::cout << NEW_LINE;
            try {
                command = commandMap.at(input);
                choosing = false;
            } catch (const std::out_of_range &error) {
                std::cout << "that is not a valid choice" << NEW_LINE;
                UserInterfaceHelpers::waitForEnterKey();
            }
        }
        return command;
    }
}
