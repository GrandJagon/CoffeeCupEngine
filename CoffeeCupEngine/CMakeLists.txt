# Add warning dislay to existing compile flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") 

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/lib")


if(UNIX)
    message("This is ${CMAKE_SYSTEM_NAME}")
    add_definitions(-DCCE_PLATFORM_LINUX)
elseif(WIN32)
    message("This is windows")
    add_definitions(-DCCE_PLATFORM_WINDOWS)
endif()

# Adding GLM CMakeLists
add_subdirectory(vendors/glm)

# Building STB_IMAGE
file(GLOB STB_IMAGE_SRC "vendors/stb_image/*.cpp")
file(GLOB STB_IMAGE_H "vendors/stb_image/*.h")
add_library(STB_IMAGE SHARED ${STB_IMAGE_SRC} ${STB_IMAGE_H})



# Finding required  ---------------- TO BE TESTED ON WINDOWS
find_package(OpenGL REQUIRED)
#find_package(glfw3 REQUIRED)
#find_package(GLUT REQUIRED) those are not needed anymore
find_package(GLEW REQUIRED)
find_package(SDL2 REQUIRED)


# Setting lib folders as variable
set(LIBS_DIR ${OPENGL_INCLUDE_DIRS}  ${GLEW_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})

# Setting libs list as variable
set(LIBS ${OPENGL_LIBRARIES}  ${GLEW_LIBRARIES} ${SDL2_LIBRARIES} STB_IMAGE)

# Building engine as shared library
add_library(CCEngine SHARED
src/events/eventManager.cpp
src/game/scenes/scene.cpp
src/game/scenes/sceneManager.cpp
src/game/game.cpp
src/game/ECS/entity.cpp
src/game/ECS/components/spriteComponent.cpp
src/game/ECS/components/transformComponent.cpp
src/game/ECS/component.cpp
src/platform/OpenGL/GLIndexBuffer.cpp
src/platform/OpenGL/GLVertexArray.cpp
src/platform/OpenGL/GLShader.cpp
src/platform/OpenGL/GLRenderer.cpp
src/platform/OpenGL/GlUtils.cpp
src/platform/OpenGL/GLVertexBufferLayout.cpp
src/platform/OpenGL/GLTextureManager.cpp
src/platform/OpenGL/GLVertexBuffer.cpp
src/platform/SDL/SDLInputHandler.cpp
src/platform/SDL/SDLWindow.cpp
src/rendering/shader.cpp
src/rendering/quad.cpp
src/rendering/indexBuffer.cpp
src/rendering/renderer.cpp
src/rendering/camera.cpp
src/rendering/texture.cpp
src/rendering/window.cpp
src/rendering/textureManager.cpp
src/rendering/vertexBuffer.cpp
src/rendering/vertexArray.cpp
src/rendering/vertexBufferLayout.cpp
src/input/inputContextChain.cpp
src/input/inputHandler.cpp
src/input/keyboardInputContext.cpp
src/input/bitmask.cpp
src/input/inputManager.cpp
)

target_precompile_headers(
    CCEngine PUBLIC
    src/CCEnginePrecompiled.h
)

# Adds the following directories to the target include directories
target_include_directories(
    CCEngine PUBLIC
    ${LIBS_DIR}
    src/
    utils/
    vendors/glm/
    vendors/imgui/
    vendors/stb_image/
)

target_link_libraries(CCEngine PUBLIC ${LIBS})

