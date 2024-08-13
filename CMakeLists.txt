cmake_minimum_required(VERSION 3.20)
project(algorithm)


# 库文件路径
set(LIBPATH "${PROJECT_SOURCE_DIR}/lib")
set(BINPATH "${PROJECT_SOURCE_DIR}/bin")

set(STATIC 1)
set(SHARED 0)


# 配置文件
add_definitions(-DDEBUG)

# test
add_subdirectory(test)
# src
add_subdirectory(src)
