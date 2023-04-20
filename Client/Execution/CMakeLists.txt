set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

add_executable(execclient main.c)

target_link_libraries(execclient PRIVATE Client)