cmake_minimum_required(VERSION 3.20)
project(algorithm)


# 库文件路径
set(LIBPATH "${PROJECT_SOURCE_DIR}/lib")
set(BINPATH "${PROJECT_SOURCE_DIR}/bin")

set(STATIC ON)
set(SHARED OFF)


# 配置文件
# add_definitions(-DDEBUG)

# src
add_subdirectory(src)
# tools
add_subdirectory(tools)

# test
add_subdirectory(test)
