cmake_minimum_required(VERSION 3.21)
project(lepre_tartaruga)

set(CMAKE_CXX_STANDARD 14)

add_executable(lepre_tartaruga main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(lepre_tartaruga LINK_PUBLIC ${RAYLIBRARY} winmm)