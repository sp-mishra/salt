cmake_minimum_required(VERSION 3.9)
project(salt)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(/usr/local/include)
include_directories(src/salt/)
include_directories(src/redbase/)
include_directories(src/third_party/rapidjson/include)
include_directories(src/third_party/spdlog/include)
include_directories(src/third_party/fmt/include)
#include_directories(src/third_party/leveldb)
include_directories(src/third_party/parallel-hashmap)
include_directories(src/third_party/oatpp)
include_directories(src/third_party/argh)
include_directories(src/third_party/xxhash_cpp/include)

file(GLOB
        SQLITE_C_SOURCE_FILES
        "src/third_party/sqlite/sqlite3.c"
        "src/third_party/sqlite/sqlite3.h"
        "src/third_party/sqlite/sqlite3ext.h"
        )

add_subdirectory(src/third_party/oatpp oatpp)
add_executable(
        salt
        ${SQLITE_C_SOURCE_FILES}
        src/salt/App.cpp
        src/salt/exceptions/BaseException.hpp
        src/salt/exceptions/StorageException.hpp
        src/salt/exceptions/ParseException.hpp
        src/salt/utils/Singleton.hpp
        src/salt/utils/NonCopyable.hpp
        src/salt/utils/Log.hpp
        src/salt/utils/Options.hpp
        src/salt/models/Status.hpp
        src/salt/constants/Consts.hpp
        src/salt/utils/FileSystemUtilities.hpp
        src/salt/AppComponent.hpp src/salt/dto/DTOs.hpp src/salt/controller/MyController.cpp src/salt/controller/MyController.hpp)

find_library(LEVELDB_LIB leveldb)
find_package(oatpp 1.1.0 REQUIRED)
message("LEVELDB_LIB: ${LEVELDB_LIB}")
message("OAT_LIB: ${oatpp}")
message("CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries(salt oatpp  ${LEVELDB_LIB})

