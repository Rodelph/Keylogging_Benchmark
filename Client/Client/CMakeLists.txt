add_library(
    Client
    src/client.c
    src/headers/client.h
    )

target_include_directories(Client PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")