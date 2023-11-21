cmake_minimum_required(VERSION 3.16.3)


if (WIN32)
    add_definitions(-DCCE_PLATFORM_WINDOWS)
    # Set your Visual Studio generator
    set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)
    # Optionally, you can set the Visual Studio version, e.g., "Visual Studio 2019"
else()
    add_definitions(-DCCE_PLATFORM_LINUX)
    set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)
endif()

message("C++ compiler: ${CMAKE_CXX_COMPILER}")
message("C compiler:   ${CMAKE_C_COMPILER}")
message("System Name: ${CMAKE_SYSTEM_NAME}")
message("Generator:   ${CMAKE_GENERATOR}")

project(CoffeeCupEngine CXX)



# Include GLEW in the CMake search path
list(APPEND CMAKE_PREFIX_PATH ${GLEW_ROOT})

# Find the GLEW package
#find_package(GLEW REQUIRED)


#set(GLEW_INCLUDE_DIR "/vendors/glew-2.2.0/include/")
set(GLEW_LIBRARIES "/vendors/glew-2.2.0/lib/")
# Adds both subdir CMakeLists.txt to the build
add_subdirectory(CoffeeCupEngine)
add_subdirectory(ExampleGame)