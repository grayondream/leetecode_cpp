cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_COMPILER D:/application/mingw64/bin/gcc.exe)
set(CMAKE_CXX_COMPILER D:/application/mingw64/bin/g++.exe)
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

project(leetecode)
include_directories(problems/1_100)
include_directories(problems/301_400)
include_directories(problems/701_800)
include_directories(problems/801_900)
include_directories(problems/901_1000)
include_directories(problems/1501_1600)

include_directories(utils)


set(SOURCE_FILES main.cpp)

add_executable(main ${SOURCE_FILES})