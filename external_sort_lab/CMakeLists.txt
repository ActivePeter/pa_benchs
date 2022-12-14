cmake_minimum_required(VERSION 3.10)
project(leetcode)

# IF (NOT CMAKE_BUILD_TYPE)
#     set(CMAKE_BUILD_TYPE "Release" CACHE STRING
#         "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
# ENDIF()


# find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 11)

#项目源码
set (SRC_DIR src)
include_directories (${SRC_DIR})
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp ${SRC_DIR}/*.cc)
add_executable (${PROJECT_NAME} ${SRC_FILES} )

#eigen3
# set (eigen3_dir third/eigen-3.3.9)
# add_subdirectory(${eigen3_dir})
# include_directories (${eigen3_dir})

# add_executable(Rasterizer main.cpp rasterizer.hpp rasterizer.cpp Triangle.hpp Triangle.cpp)
target_link_libraries(leetcode)
