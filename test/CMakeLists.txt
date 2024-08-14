cmake_minimum_required(VERSION 3.20)
project(test)

set(EXECUTABLE_OUTPUT_PATH ${BINPATH})
add_executable(test test_main.c)
# target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 链接 simple tools 库
target_link_libraries(test PUBLIC simple tools)
target_link_directories(test PUBLIC ${LIBPATH})
