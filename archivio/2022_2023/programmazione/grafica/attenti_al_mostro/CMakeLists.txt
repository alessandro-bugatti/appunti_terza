cmake_minimum_required(VERSION 3.21)
project(attenti_al_mostro)

set(CMAKE_CXX_STANDARD 14)

add_executable(attenti_al_mostro main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(attenti_al_mostro LINK_PUBLIC ${RAYLIBRARY} winmm)