#ifndef CPP2CLIENT_COMMANDSELECTOR_H
#define CPP2CLIENT_COMMANDSELECTOR_H

#include <unordered_map>
#include "CommandName.h"

namespace cpp2 {
    class CommandSelector {
    public:
        CommandSelector();

        [[nodiscard]] CommandName waitForCommandInput() const;

    private:
        const std::unordered_map<std::string, CommandName> commandMap;
    };
}

#endif //CPP2CLIENT_COMMANDSELECTOR_H
