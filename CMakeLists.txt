cmake_minimum_required(VERSION 3.5)
project(leetecode)

include_directories(problems)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

add_executable(main ${SOURCE_FILES})