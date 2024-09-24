cmake_minimum_required(VERSION 3.21)
project(caricamento_immagini)

set(CMAKE_CXX_STANDARD 17)

add_executable(caricamento_immagini main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(caricamento_immagini LINK_PUBLIC ${RAYLIBRARY} winmm)