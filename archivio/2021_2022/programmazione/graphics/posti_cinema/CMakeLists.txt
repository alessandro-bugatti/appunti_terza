cmake_minimum_required(VERSION 3.21)
project(posti_cinema)

set(CMAKE_CXX_STANDARD 14)

add_executable(posti_cinema main.cpp)

target_link_libraries(posti_cinema LINK_PUBLIC  raylib opengl32 gdi32 winmm)