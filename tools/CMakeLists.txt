cmake_minimum_required(VERSION 3.20)
project(tools)


# 递归搜索所有的源文件
file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
# add_library(tools STATIC ${SRC})

set(LIBRARY_OUTPUT_PATH ${LIBPATH})
if(${STATIC})
    add_library(tools STATIC ${SRC})
endif(${STATIC})

if(${SHARED})
    add_library(tools SHARED ${SRC})
endif(${SHARED})

target_include_directories(tools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

