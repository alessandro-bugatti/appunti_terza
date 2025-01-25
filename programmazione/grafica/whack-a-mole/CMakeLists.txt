cmake_minimum_required(VERSION 3.5)
project(whack-a-mole)

set(CMAKE_CXX_STANDARD 20)

add_executable(whack-a-mole main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(whack-a-mole LINK_PUBLIC ${RAYLIBRARY} winmm)