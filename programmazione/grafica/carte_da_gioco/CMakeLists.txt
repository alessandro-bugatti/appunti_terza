cmake_minimum_required(VERSION 3.5)
project(carte_da_gioco)

set(CMAKE_CXX_STANDARD 20)

add_executable(carte_da_gioco main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(carte_da_gioco LINK_PUBLIC ${RAYLIBRARY} winmm)