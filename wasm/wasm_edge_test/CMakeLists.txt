cmake_minimum_required(VERSION 3.10)
project(leetcode)

# wasmedge
file(STRINGS "${PROJECT_SOURCE_DIR}/cmake_config.txt " wasmedge_lib_fpath LIMIT_COUNT 1 REGEX "wasmedge_lib_fpath ?")
string(REGEX REPLACE "wasmedge_lib_fpath " "" wasmedge_lib_fpath ${wasmedge_lib_fpath})
message(STATUS "wasmedge_lib_fpath: " ${wasmedge_lib_fpath})

file(STRINGS "${PROJECT_SOURCE_DIR}/cmake_config.txt " wasmedge_lib_incpath LIMIT_COUNT 1 REGEX "wasmedge_lib_incpath ?")
string(REGEX REPLACE "wasmedge_lib_incpath " "" wasmedge_lib_incpath ${wasmedge_lib_incpath})
message(STATUS "wasmedge_lib_incpath: " ${wasmedge_lib_incpath})


set(CMAKE_CXX_STANDARD 11)

#项目源码
set (SRC_DIR src)
include_directories (${SRC_DIR} ${wasmedge_lib_incpath})
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp ${SRC_DIR}/*.cc)
add_executable (${PROJECT_NAME} ${SRC_FILES} )

target_link_libraries(leetcode ${wasmedge_lib_fpath})
