cmake_minimum_required(VERSION 3.21)
project(lettura_stringhe)

set(CMAKE_CXX_STANDARD 17)

add_executable(lettura_stringhe main.cpp)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(lettura_stringhe LINK_PUBLIC ${RAYLIBRARY} winmm)