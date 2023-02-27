cmake_minimum_required(VERSION 3.21)
project(life)

set(CMAKE_CXX_STANDARD 14)

add_executable(life main.cpp)

target_link_libraries(life LINK_PUBLIC  raylib opengl32 gdi32 winmm)