cmake_minimum_required(VERSION 3.10)
project(leetcode)

function(load_cmake_config path)
    file(STRINGS "${PROJECT_SOURCE_DIR}/cmake_config.txt " ret LIMIT_COUNT 1 REGEX "${path} ?")
    string(REGEX REPLACE "${path} " "" ret ${ret})
    SET(${path} ${ret} PARENT_SCOPE)
endfunction()

# wasmedge
load_cmake_config(wasmedge_lib_fpath)
message(STATUS "wasmedge_lib_fpath: " ${wasmedge_lib_fpath})

load_cmake_config(wasmedge_lib_incpath)
message(STATUS "wasmedge_lib_incpath: " ${wasmedge_lib_incpath})


set(CMAKE_CXX_STANDARD 11)

#项目源码
include_directories (${SRC_DIR} ${wasmedge_lib_incpath})

set (SRC_DIR src)
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp ${SRC_DIR}/*.cc)
add_executable (${PROJECT_NAME} ${SRC_FILES} )
target_link_libraries(${PROJECT_NAME} ${wasmedge_lib_fpath})

set (SRC_DIR src_compiler)
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp ${SRC_DIR}/*.cc)
add_executable(aot_compiler  ${SRC_FILES} )
target_link_libraries(aot_compiler ${wasmedge_lib_fpath})

