#ifndef CPP2CLIENT_CONSOLEPRINTHELPERS_H
#define CPP2CLIENT_CONSOLEPRINTHELPERS_H

#include <filesystem>
#include <iostream>
#include "Constants.h"

namespace cpp2 {
    class ConsolePrintHelpers {
    public:
        static void printCommandOptions() {
            std::cout
                    << "Choose a command by number: " << NEW_LINE
                    << "1. Server information" << NEW_LINE
                    << "2. Request directory listing" << NEW_LINE
                    << "3. Download remote file" << NEW_LINE
                    << "4. Upload local file" << NEW_LINE
                    << "5. Rename directory or file" << NEW_LINE
                    << "6. Delete directory or file" << NEW_LINE
                    << "7. Create new directory" << NEW_LINE
                    << "8. Synchronize local directory with remote" << NEW_LINE
                    << "9. Close connection to server and quit" << NEW_LINE
                    << ENTER_CHOICE_PROMPT;
        }

        static void waitForEnterKey() {
            std::cout << ENTER_TO_CONTINUE_PROMPT << NEW_LINE;
            std::cin.ignore();
            std::cin.get();
        }

        static std::filesystem::path waitForPathInput() {
            // ask user for relative path
            std::cout << ENTER_DIRECTORY_PROMPT;
            std::string input;
            std::cin >> input;
            std::cout << NEW_LINE;

            // check if input contains / or \ at the start
            // because we add a path separator ourselves
            if (input.rfind('/', 0) == 0
                || input.rfind('\\', 0) == 0) {
                throw std::logic_error{"do not start path with '/' or '\\'"};
            }

            // check if input contains any characters
            // that can be used to refer to paths outside of sync directory
            if (input.rfind('.', 0) != std::string::npos
                || input.rfind('~', 0) != std::string::npos
                || input.rfind("..", 0) != std::string::npos) {
                throw std::logic_error{"path cannot contain '.', '..' or '~'"};
            }

            return input;
        }

    private:
        ConsolePrintHelpers() = default;
    };
}

#endif //CPP2CLIENT_CONSOLEPRINTHELPERS_H
