cmake_minimum_required(VERSION 3.15)
project(raylib_progetti C CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(RaylibApp)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

add_subdirectory(libs/raylib)
add_subdirectory(projects)

