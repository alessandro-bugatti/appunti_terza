cmake_minimum_required(VERSION 3.21)
project(raylib_network_sample_portable)

set(CMAKE_CXX_STANDARD 14)

add_executable(raylib_network_sample_portable main.cpp src/DatagramSocket.cpp src/DatagramSocket.h
            src/UDP_Communicator.cpp src/UDP_Communicator.h)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${RAYLIBRARY}  winmm wsock32 ws2_32)

