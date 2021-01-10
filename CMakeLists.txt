cmake_minimum_required(VERSION 3.5)
project(leetecode)

include_directories(problems/1_100)
include_directories(problems/701_800)
include_directories(utils)


set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

add_executable(main ${SOURCE_FILES})