cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 20)

project(Cpp2Client)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(INCLUDES
        include/Constants.h
        include/ConsolePrintHelpers.h
        include/Application.h
        include/commands/CommandSelector.h
        include/communication/Client.h
        include/communication/ServerConnection.h
        include/commands/AbstractCommand.h
        include/commands/CommandName.h
        include/commands/CommandFactory.h
        include/commands/implementations/ServerInformationCommand.h
        include/commands/implementations/RequestDirectoryListingCommand.h
        include/commands/implementations/DownloadRemoteFileCommand.h
        include/commands/implementations/UploadLocalFileCommand.h
        include/commands/implementations/RenameCommand.h
        include/commands/implementations/DeleteCommand.h
        include/commands/implementations/MakeDirectoryCommand.h
        include/commands/implementations/QuitCommand.h
        include/commands/implementations/SynchronizeDirectoryCommand.h
        include/filesystem/FileSystemManager.h
        include/filesystem/FileInfo.h
        include/filesystem/FileType.h
        include/filesystem/FileTypeMapper.h)

set(SOURCE_FILES
        src/Main.cpp
        src/Application.cpp
        src/commands/CommandSelector.cpp
        src/communication/Client.cpp
        src/communication/ServerConnection.cpp
        src/commands/CommandFactory.cpp
        src/commands/implementations/ServerInformationCommand.cpp
        src/commands/implementations/RequestDirectoryListingCommand.cpp
        src/commands/implementations/DownloadRemoteFileCommand.cpp
        src/commands/implementations/UploadLocalFileCommand.cpp
        src/commands/implementations/RenameCommand.cpp
        src/commands/implementations/DeleteCommand.cpp
        src/commands/implementations/MakeDirectoryCommand.cpp
        src/commands/implementations/QuitCommand.cpp
        src/commands/implementations/SynchronizeDirectoryCommand.cpp
        src/filesystem/FileSystemManager.cpp)

add_executable(Cpp2Client
        ${INCLUDES}
        ${SOURCE_FILES}
        )

target_link_libraries(Cpp2Client PRIVATE Threads::Threads)
