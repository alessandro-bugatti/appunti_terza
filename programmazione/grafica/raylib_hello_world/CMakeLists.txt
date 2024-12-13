cmake_minimum_required(VERSION 3.5)
project(raylib_hello_world)

set(CMAKE_CXX_STANDARD 20)

add_executable(raylib_hello_world main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(raylib_hello_world LINK_PUBLIC ${RAYLIBRARY} winmm)