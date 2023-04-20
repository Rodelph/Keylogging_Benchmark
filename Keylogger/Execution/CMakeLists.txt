if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(fmt CONFIG REQUIRED)
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS off)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

add_executable(exec main.cpp)

target_compile_features(exec PRIVATE cxx_std_20)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(exec PRIVATE Keylogging fmt::fmt)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(exec PRIVATE Keylogging)
endif()
