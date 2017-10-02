cmake_minimum_required(VERSION 3.7)

project(SDL_App)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDL_App sdl_app.cpp sdl_app.h Screen.h Screen.cpp Particle.cpp Particle.h)
target_link_libraries(SDL_App ${SDL2_LIBRARIES})