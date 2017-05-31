cmake_minimum_required(VERSION 3.1)
project(ApplicationMain CXX)

#set(CMAKE_C_COMPILER "/usr/bin/gcc")
#set(CMAKE_CXX_COMPILER "/usr/bin/g++")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -fdump-record-layouts")


#add_definitions(-std=c++11)

#include_directories(
#        . # to be able to make google style includes
#)

add_subdirectory(test)
add_subdirectory(source)
