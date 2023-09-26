
cmake_minimum_required(VERSION 3.16)

project(oop_lab1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_library(foo foo.h foo.cpp)
add_library(helps help.h help.cpp)

link_libraries(foo helps)

add_executable(main main.cpp)

