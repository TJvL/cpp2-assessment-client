#ifndef CPP2CLIENT_COMMANDFACTORY_H
#define CPP2CLIENT_COMMANDFACTORY_H

#include <memory>
#include "CommandName.h"
#include "AbstractCommand.h"

namespace cpp2 {
    class CommandFactory {
    public:
        std::unique_ptr<const AbstractCommand> createCommand(const CommandName commandName) const;

    private:
        template<ACommand AC>
        std::unique_ptr<const AC> create() const {
            return std::make_unique<const AC>();
        }
    };
}

#endif //CPP2CLIENT_COMMANDFACTORY_H
