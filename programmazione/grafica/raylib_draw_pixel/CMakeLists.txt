cmake_minimum_required(VERSION 3.5)
project(raylib_draw_pixel)

set(CMAKE_CXX_STANDARD 20)

add_executable(raylib_draw_pixel main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(raylib_draw_pixel LINK_PUBLIC ${RAYLIBRARY} winmm)