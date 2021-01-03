#ifndef CPP2CLIENT_ABSTRACTCOMMAND_H
#define CPP2CLIENT_ABSTRACTCOMMAND_H

#include <type_traits>
#include "../communication/ServerConnection.h"
#include "../filesystem/FileSystemManager.h"

namespace cpp2 {
    class AbstractCommand {
    public:
        virtual ~AbstractCommand() = default;

        virtual bool execute(ServerConnection &serverConnection, FileSystemManager &syncManager) = 0;

    protected:
        AbstractCommand() = default;
    };

    template<class C>
    concept ACommand = std::is_base_of<AbstractCommand, C>::value;
}

#endif //CPP2CLIENT_ABSTRACTCOMMAND_H