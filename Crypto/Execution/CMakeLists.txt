if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(fmt CONFIG REQUIRED)
endif()

find_package(OPENSSL REQUIRED OpenSSL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS off)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
include_directories(${OPENSSL_INCLUDE_DIRS})
add_executable(execcrypt main.cpp)

target_compile_features(execcrypt PRIVATE cxx_std_20)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(execcrypt PRIVATE OpenSSL::SSL OpenSSL::Crypto)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(execcrypt PRIVATE OpenSSL::SSL OpenSSL::Crypto)
endif()
