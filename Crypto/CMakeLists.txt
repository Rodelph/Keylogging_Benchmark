cmake_minimum_required(VERSION 3.21)

project(crypto VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS off)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(Decrypt)
add_subdirectory(Encrypt)
add_subdirectory(Execution)
