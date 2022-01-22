cmake_minimum_required(VERSION 3.21)
project(slider)

set(CMAKE_CXX_STANDARD 14)

add_executable(slider main.cpp)

target_link_libraries(slider LINK_PUBLIC  raylib winmm)