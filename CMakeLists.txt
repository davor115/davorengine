cmake_minimum_required(VERSION 2.6)

project(DAVORENGINE)

include_directories(src)

add_library(davorengine
src/davorengine/Camera.cpp
src/davorengine/Camera.h
src/davorengine/dummy.cpp
src/davorengine/Core.h
src/davorengine/Core.cpp
src/davorengine/Component.h
src/davorengine/Component.cpp
src/davorengine/Entity.h
src/davorengine/Entity.cpp
src/davorengine/Environment.cpp
src/davorengine/Environment.h
src/davorengine/Exception.cpp
src/davorengine/Exception.h
src/davorengine/triangle.cpp
src/davorengine/Keyboard.h
src/davorengine/Keyboard.cpp
src/davorengine/Transform.h
src/davorengine/Transform.cpp
src/davorengine/Engineincludes.h
)

target_link_libraries(davorengine SDL2 rend)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
)
if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_executable(game
 src/game/main.cpp
 src/game/TriangleRenderer2.cpp
 src/game/MeshRenderer.h
 src/game/TriangleRenderer.cpp
)

target_link_libraries(game davorengine)