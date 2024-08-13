cmake_minimum_required(VERSION 3.20)
project(test)


set(EXECUTABLE_OUTPUT_PATH ${BINPATH})
add_executable(test test.c)
target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
