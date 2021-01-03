#ifndef CPP2CLIENT_COMMANDFACTORY_H
#define CPP2CLIENT_COMMANDFACTORY_H

#include <memory>
#include "CommandName.h"
#include "AbstractCommand.h"

namespace cpp2 {
    class CommandFactory {
    public:
        CommandFactory() = default;

        ~CommandFactory() = default;

        std::unique_ptr<AbstractCommand> createCommand(CommandName commandName) const;

    private:
        template<ACommand AC>
        std::unique_ptr<AC> create() const {
            return std::make_unique<AC>();
        }
    };
}

#endif //CPP2CLIENT_COMMANDFACTORY_H
