add_library(
    Keylogging
    src/keylogging.cpp
    src/headers/keylogging.hpp
    )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS off)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

target_compile_features(Keylogging PRIVATE cxx_std_20)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(fmt CONFIG REQUIRED)
    target_link_libraries(Keylogging PRIVATE fmt::fmt-header-only)  
endif()
target_include_directories(Keylogging PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")