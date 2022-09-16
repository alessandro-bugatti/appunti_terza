cmake_minimum_required(VERSION 3.21)
project(andamento_covid)

set(CMAKE_CXX_STANDARD 14)

add_executable(andamento_covid main.cpp)

target_link_libraries(andamento_covid LINK_PUBLIC  raylib opengl32 gdi32 winmm)