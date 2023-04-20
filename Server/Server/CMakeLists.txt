add_library(
    Server
    src/server.c
    src/headers/server.h
    )

target_include_directories(Server PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")