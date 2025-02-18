cmake_minimum_required(VERSION 3.5)
project(grafici_filtro)

set(CMAKE_CXX_STANDARD 20)

add_executable(grafici_filtro main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(grafici_filtro LINK_PUBLIC ${RAYLIBRARY} winmm)