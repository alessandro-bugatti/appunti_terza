cmake_minimum_required(VERSION 3.21)
project(palline)

set(CMAKE_CXX_STANDARD 14)

add_executable(raylib_template_leggero main.cpp)

target_link_libraries(raylib_template_leggero LINK_PUBLIC  raylib opengl32 gdi32 winmm)