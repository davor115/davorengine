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
src/davorengine/MeshRenderer.h
src/davorengine/MeshRenderer.cpp
src/davorengine/stb_vorbis.h
src/davorengine/Engineincludes.h
src/davorengine/Resources.cpp
src/davorengine/Resources.h
src/davorengine/Resource.cpp
src/davorengine/Resource.h
src/davorengine/Mesh.h
src/davorengine/Mesh.cpp
src/davorengine/Material.h
src/davorengine/Material.cpp
src/davorengine/EngineKeyboard.h
src/davorengine/Collision.cpp
src/davorengine/Collision.h
src/davorengine/GUI.h
src/davorengine/GUI.cpp
src/davorengine/Audio.h
src/davorengine/Audio.cpp
)

if(MSVC)
  target_link_libraries(davorengine SDL2 rend OpenAL32)
else()
  target_link_libraries(davorengine SDL2 rend openal)
endif()

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
  src/rend/stb_image.h
)
if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_executable(game
 src/game/Game.cpp
 src/game/main.cpp
 src/game/TriangleRenderer2.cpp
)

target_link_libraries(game davorengine)
