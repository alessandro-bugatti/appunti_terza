cmake_minimum_required(VERSION 3.21)
project(scrabble)

set(CMAKE_CXX_STANDARD 17)

add_executable(scrabble main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(scrabble LINK_PUBLIC ${RAYLIBRARY} winmm)