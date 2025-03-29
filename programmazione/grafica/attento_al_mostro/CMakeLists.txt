cmake_minimum_required(VERSION 3.5)
project(attento_al_mostro)

set(CMAKE_CXX_STANDARD 20)

add_executable(attento_al_mostro main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(attento_al_mostro LINK_PUBLIC ${RAYLIBRARY} winmm)