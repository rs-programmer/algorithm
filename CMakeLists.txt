cmake_minimum_required(VERSION 3.20)
project(algorithm)


# 全局头文件
include_directories("${PROJECT_SOURCE_DIR}/include")

# 库文件路径
set(LIBPATH "${PROJECT_SOURCE_DIR}/lib")
set(BINPATH "${PROJECT_SOURCE_DIR}/bin")

set(STATIC ON)
set(SHARED OFF)

# cmake 代码编译版本 添加GDB调试功能
set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
# set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# 配置文件
# add_definitions(-DDEBUG)

# src
add_subdirectory(src)
# tools
add_subdirectory(tools)

# test
add_subdirectory(test)
