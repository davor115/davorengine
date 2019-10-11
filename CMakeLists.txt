cmake_minimum_required(VERSION 2.6)

project(DAVORENGINE)

add_library(davorengine
src/davorengine/dummy.cpp
src/davorengine/davorengine.h
src/davorengine/davorengine.cpp
)

target_link_libraries(davorengine SDL2 opengl32 glew32)

add_executable(game
 src/game/main.cpp
)

target_link_libraries(game davorengine)