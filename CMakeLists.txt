cmake_minimum_required(VERSION 3.21)

project(OSS VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(Server)
add_subdirectory(Client)
add_subdirectory(Keylogger)
add_subdirectory(Crypto)