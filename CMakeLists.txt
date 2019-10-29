cmake_minimum_required(VERSION 2.6)

project(DAVORENGINE)

include_directories(src)

add_library(davorengine
src/davorengine/dummy.cpp
src/davorengine/Core.h
src/davorengine/Core.cpp
src/davorengine/Component.h
src/davorengine/Component.cpp
src/davorengine/Entity.h
src/davorengine/Environment.cpp
src/davorengine/Environment.h
src/davorengine/Exception.cpp
src/davorengine/Exception.h
src/davorengine/triangle.cpp
src/davorengine/Keyboard.h
src/davorengine/Keyboard.cpp
src/davorengine/TriangleRenderer.h
src/davorengine/TriangleRenderer.cpp
)

target_link_libraries(davorengine SDL2 opengl32 glew32)

add_executable(game
 src/game/main.cpp
)

target_link_libraries(game davorengine)