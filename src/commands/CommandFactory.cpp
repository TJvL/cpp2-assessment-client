#include "../../include/commands/CommandFactory.h"
#include "../../include/commands/implementations/ServerInformationCommand.h"
#include "../../include/commands/implementations/RequestDirectoryListingCommand.h"
#include "../../include/commands/implementations/MakeDirectoryCommand.h"
#include "../../include/commands/implementations/DownloadRemoteFileCommand.h"
#include "../../include/commands/implementations/UploadLocalFileCommand.h"
#include "../../include/commands/implementations/RenameCommand.h"
#include "../../include/commands/implementations/DeleteCommand.h"
#include "../../include/commands/implementations/SynchronizeDirectoryCommand.h"
#include "../../include/commands/implementations/QuitCommand.h"

namespace cpp2 {
    std::unique_ptr<AbstractCommand> CommandFactory::createCommand(CommandName commandName, ServerConnection& serverConnection, FileSystemManager &fileSystemManager) const {
        switch (commandName) {
            case SERVER_INFORMATION:
                return std::move(CommandFactory::create<ServerInformationCommand>(serverConnection, fileSystemManager));
            case REQUEST_DIRECTORY_LISTING:
                return std::move(CommandFactory::create<RequestDirectoryListingCommand>(serverConnection, fileSystemManager));
            case MAKE_DIRECTORY:
                return std::move(CommandFactory::create<MakeDirectoryCommand>(serverConnection, fileSystemManager));
            case DOWNLOAD_REMOTE_FILE:
                return std::move(CommandFactory::create<DownloadRemoteFileCommand>(serverConnection, fileSystemManager));
            case UPLOAD_LOCAL_FILE:
                return std::move(CommandFactory::create<UploadLocalFileCommand>(serverConnection, fileSystemManager));
            case RENAME:
                return std::move(CommandFactory::create<RenameCommand>(serverConnection, fileSystemManager));
            case DELETE:
                return std::move(CommandFactory::create<DeleteCommand>(serverConnection, fileSystemManager));
            case SYNC_DIRECTORY:
                return std::move(CommandFactory::create<SynchronizeDirectoryCommand>(serverConnection, fileSystemManager));
            case QUIT:
                return std::move(CommandFactory::create<QuitCommand>(serverConnection, fileSystemManager));
            default:
                throw std::runtime_error("the given command name has no implementation");
        }
    }
}
