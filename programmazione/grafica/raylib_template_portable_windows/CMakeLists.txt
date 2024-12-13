cmake_minimum_required(VERSION 3.5)
project(raylib_template_portable_windows)

set(CMAKE_CXX_STANDARD 20)

add_executable(raylib_template_portable_windows main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(raylib_template_portable_windows LINK_PUBLIC ${RAYLIBRARY} winmm)