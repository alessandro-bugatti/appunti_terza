cmake_minimum_required(VERSION 3.26.4)
project(chat)

set(CMAKE_CXX_STANDARD 17)

add_executable(chat main.cpp src/DatagramSocket.cpp src/DatagramSocket.h
        src/UDP_Communicator.cpp src/UDP_Communicator.h
        src/UDP_Server.cpp src/UDP_Server.h)

if(WIN32)
    target_link_libraries(chat wsock32 ws2_32)
endif()
