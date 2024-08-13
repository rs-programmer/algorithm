cmake_minimum_required(VERSION 3.20)
project(simple)


set(LIBRARY_OUTPUT_PATH ${LIBPATH})
if(${STATIC})
    add_library(simple STATIC simple.c)
endif(${STATIC})

if(${SHARED})
    add_library(simple SHARED simple.c)
endif(${SHARED})

target_include_directories(simple PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

