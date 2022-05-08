cmake_minimum_required(VERSION 3.16)
project(First)

set(CMAKE_CXX_STANDARD 20)

add_executable(First main.cpp Users.h Users.cpp Database.h Database.cpp)
