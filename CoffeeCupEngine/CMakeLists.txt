# Add warning dislay to existing compile flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") 


if(UNIX)
    message("This is ${CMAKE_SYSTEM_NAME}")
    add_definitions(-DCCE_PLATFORM_LINUX)
elseif(WIN32)
    message("This is windows")
    add_definitions(-DCCE_PLATFORM_WINDOWS)
endif()

# Adding GLM CMakeLists
add_subdirectory(vendors/glm)

# Setting the proper build output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/bin")

# Building STB_IMAGE
file(GLOB STB_IMAGE_SRC "vendors/stb_image/*.cpp")
file(GLOB STB_IMAGE_H "vendors/stb_image/*.h")
add_library(STB_IMAGE SHARED ${STB_IMAGE_SRC} ${STB_IMAGE_H})

# Defining SDL2 directories
set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/vendors/SDL2")

# Include GLEW in the CMake search path
#list(APPEND CMAKE_PREFIX_PATH ${GLEW_ROOT})
#set(GLEW_LIBRARIES "/vendors/glew-2.2.0/lib/")
#set(GLEW_ROOT "${CMAKE_SOURCE_DIR}/libs/glew-2.2.0")

set(GLEW_INCLUDE_DIRS "${CMAKE_CURRENTT_LIST_DIR}/vendors/glew")
set(FREEGLUT_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/vendors/freeglut")

# Setting proper libraries according to CPU architecture
if(WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8) # 64 bit architecture
        set(FREEGLUT_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/libs/freeglut/x64/freeglut.dll")
        set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/libs/SDL2/SDL2.dll")
        set(GLEW_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/libs/glew/bin/x64/glew32.dll")
    else() # 32 bits architecture
        set(FREEGLUT_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/libs/freeglut/freeglut.dll")
        set(GLEW_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/libs/glew/bin/Win32/glew32.dll")
    endif()
else()
    message("A freeglut library need to be added for linux into libs/freeglut/")
    return()
endif()


# Finding required  ---------------- TO BE TESTED ON WINDOWS
find_package(OpenGL REQUIRED)
#find_package(glfw3 REQUIRED)
#find_package(FREEGLUT REQUIRED) 
#find_package(GLEW REQUIRED)
#find_package(SDL2 REQUIRED)

# Setting lib folders as variable
set(INCLUDE_DIRS ${OPENGL_INCLUDE_DIRS}  ${GLEW_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${FREEGLUT_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS})


# Setting libs list as variable
set(LIBS ${OPENGL_LIBRARIES}  ${GLEW_LIBRARIES} ${SDL2_LIBRARIES} ${FREEGLUT_LIBRARIES} ${GLEW_LIBRARIES} STB_IMAGE)

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
src/input/inputContext.cpp
src/input/inputHandler.cpp
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
    ${INCLUDE_DIRS}
    src/
    utils/
    vendors/
    vendors/imgui/
    vendors/stb_image/
    vendors/glew/
    vendors/freeglut/
)

# Copy DLL
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2/SDL2.dll DESTINATION ${PROJECT_SOURCE_DIR}/build/bin)

if(CMAKE_SIZEOF_VOID_P EQUAL 8) # 64 bit architecture
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/libs/freeglut/x64/freeglut.dll DESTINATION ${PROJECT_SOURCE_DIR}/build/bin)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/libs/glew/bin/x64/glew32.dll DESTINATION ${PROJECT_SOURCE_DIR}/build/bin)
else()
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/libs/freeglut/freeglut.dll DESTINATION ${PROJECT_SOURCE_DIR}/build/bin)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/libs/glew/bin/Win312/glew32.dll DESTINATION ${PROJECT_SOURCE_DIR}/build/bin)
endif()

target_link_libraries(CCEngine PUBLIC ${LIBS})
