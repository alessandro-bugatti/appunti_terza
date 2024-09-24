cmake_minimum_required(VERSION 3.28)
project(two_way_communication)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp src/DatagramSocket.cpp src/DatagramSocket.h
        src/UDP_Communicator.cpp src/UDP_Communicator.h)

if(WIN32)
    target_link_libraries(two_way_communication wsock32 ws2_32)
endif()
