cmake_minimum_required(VERSION 3.0)

project(pbrain-gomoku-ai)

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# set(SOURCES
#     src/main.cpp
#     src/Args.cpp
# )
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(pbrain-gomoku-ai ${SOURCES})

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
