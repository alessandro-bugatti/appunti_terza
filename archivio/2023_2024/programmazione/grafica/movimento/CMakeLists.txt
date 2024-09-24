cmake_minimum_required(VERSION 3.21)
project(movimento)

set(CMAKE_CXX_STANDARD 14)

add_executable(movimento main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(movimento LINK_PUBLIC ${RAYLIBRARY} winmm)