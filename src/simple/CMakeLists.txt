cmake_minimum_required(VERSION 3.20)
project(simple)

file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
set(LIBRARY_OUTPUT_PATH ${LIBPATH})
if(${STATIC})
    add_library(simple STATIC ${SRC})
endif(${STATIC})

if(${SHARED})
    add_library(simple SHARED ${SRC})
endif(${SHARED})

target_include_directories(simple PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# tools
target_link_libraries(simple PUBLIC tools)
target_link_directories(simple PUBLIC ${LIBPATH})

