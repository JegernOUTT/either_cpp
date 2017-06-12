cmake_minimum_required(VERSION 3.8)
project(either_test)

include_directories(include)

add_definitions(-fconcepts -fpermissive)
set(CMAKE_CXX_STANDARD 17)

add_executable(either_test test/test.cpp)