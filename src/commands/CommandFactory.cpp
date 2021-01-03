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
    std::unique_ptr<AbstractCommand> CommandFactory::createCommand(CommandName commandName) const {
        switch (commandName) {
            case SERVER_INFORMATION:
                return CommandFactory::create<ServerInformationCommand>();
            case REQUEST_DIRECTORY_LISTING:
                return CommandFactory::create<RequestDirectoryListingCommand>();
            case MAKE_DIRECTORY:
                return CommandFactory::create<MakeDirectoryCommand>();
            case DOWNLOAD_REMOTE_FILE:
                return CommandFactory::create<DownloadRemoteFileCommand>();
            case UPLOAD_LOCAL_FILE:
                return CommandFactory::create<UploadLocalFileCommand>();
            case RENAME:
                return CommandFactory::create<RenameCommand>();
            case DELETE:
                return CommandFactory::create<DeleteCommand>();
            case SYNC_DIRECTORY:
                return CommandFactory::create<SynchronizeDirectoryCommand>();
            case QUIT:
                return CommandFactory::create<QuitCommand>();
            default:
                throw std::runtime_error("the given command name has no implementation");
        }
    }
}
