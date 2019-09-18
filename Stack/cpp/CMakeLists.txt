cmake_minimum_required(VERSION 3.14)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp main.cpp StackVector.cpp StackVector.h StackList.cpp StackList.h)