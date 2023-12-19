cmake_minimum_required(VERSION 3.21)
project(lettura_tasti)

set(CMAKE_CXX_STANDARD 14)

add_executable(lettura_tasti main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(lettura_tasti LINK_PUBLIC ${RAYLIBRARY} winmm)