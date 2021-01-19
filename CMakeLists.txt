cmake_minimum_required(VERSION 3.5)
project(leetecode)

include_directories(A:/application/Mingw/MinGW/include)
include_directories(problems/1_100)
include_directories(problems/301_400)
include_directories(problems/701_800)
include_directories(problems/801_900)
include_directories(problems/901_1000)
include_directories(problems/1501_1600)

include_directories(utils)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

add_executable(main ${SOURCE_FILES})