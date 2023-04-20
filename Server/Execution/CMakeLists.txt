set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

add_executable(execserv main.c)

target_link_libraries(execserv PRIVATE Server)