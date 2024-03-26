cmake_minimum_required(VERSION 3.21)
project(mouse)

set(CMAKE_CXX_STANDARD 17)

add_executable(mouse main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(mouse LINK_PUBLIC ${RAYLIBRARY} winmm)