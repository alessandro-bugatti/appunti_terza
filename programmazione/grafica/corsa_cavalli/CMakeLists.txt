cmake_minimum_required(VERSION 3.21)
project(corsa_cavalli)

set(CMAKE_CXX_STANDARD 14)

add_executable(corsa_cavalli main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(corsa_cavalli LINK_PUBLIC  ${RAYLIBRARY} winmm)