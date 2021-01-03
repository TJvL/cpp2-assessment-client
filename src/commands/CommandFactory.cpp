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
                return CommandFactory::create<ServerInformationCommand>(serverConnection, fileSystemManager);
            case REQUEST_DIRECTORY_LISTING:
                return CommandFactory::create<RequestDirectoryListingCommand>(serverConnection, fileSystemManager);
            case MAKE_DIRECTORY:
                return CommandFactory::create<MakeDirectoryCommand>(serverConnection, fileSystemManager);
            case DOWNLOAD_REMOTE_FILE:
                return CommandFactory::create<DownloadRemoteFileCommand>(serverConnection, fileSystemManager);
            case UPLOAD_LOCAL_FILE:
                return CommandFactory::create<UploadLocalFileCommand>(serverConnection, fileSystemManager);
            case RENAME:
                return CommandFactory::create<RenameCommand>(serverConnection, fileSystemManager);
            case DELETE:
                return CommandFactory::create<DeleteCommand>(serverConnection, fileSystemManager);
            case SYNC_DIRECTORY:
                return CommandFactory::create<SynchronizeDirectoryCommand>(serverConnection, fileSystemManager);
            case QUIT:
                return CommandFactory::create<QuitCommand>(serverConnection, fileSystemManager);
            default:
                throw std::runtime_error("the given command name has no implementation");
        }
    }
}
