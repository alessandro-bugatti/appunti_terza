cmake_minimum_required(VERSION 3.5)
project(tris)

set(CMAKE_CXX_STANDARD 20)

add_executable(tris main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(tris LINK_PUBLIC ${RAYLIBRARY} winmm)