cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 20)

project(Cpp2Client)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(Cpp2Client src/Client.cpp)

target_link_libraries(Cpp2Client PRIVATE Threads::Threads)
