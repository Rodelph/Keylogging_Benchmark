add_library(
    Decrypt
    src/decrypt.cpp
    src/headers/decrypt.hpp
    )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS off)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

target_compile_features(Decrypt PRIVATE cxx_std_20)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(fmt CONFIG REQUIRED)
    target_link_libraries(Decrypt PRIVATE fmt::fmt-header-only)  
endif()
target_include_directories(Decrypt PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")