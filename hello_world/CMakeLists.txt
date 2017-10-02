cmake_minimum_required(VERSION 3.8)
project(hello_world)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES hello_world.cpp)


set(SDL_FILES hello_world.cpp)
add_executable(hello_world ${SDL_FILES})