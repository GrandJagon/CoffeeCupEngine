cmake_minimum_required(VERSION 3.16.3)

# By default, set the C++ compiler to g++
if (NOT CMAKE_CXX_COMPILER)
    find_program(CMAKE_CXX_COMPILER g++)
endif ()

if (NOT CMAKE_C_COMPILER)
    find_program(CMAKE_C_COMPILER gcc)
endif ()

if (WIN32)
    set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)
else()
    set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)
endif()

message("C++ compiler: ${CMAKE_CXX_COMPILER}")
message("C compiler:   ${CMAKE_C_COMPILER}")
message("System Name: ${CMAKE_SYSTEM_NAME}")
message("Generator:   ${CMAKE_GENERATOR}")

project(CoffeeCupEngine)

# Set the path to the GLEW library and include directory
set(GLEW_ROOT "${CMAKE_SOURCE_DIR}/vendors/glew-2.2.0")

# Include GLEW in the CMake search path
list(APPEND CMAKE_PREFIX_PATH ${GLEW_ROOT})

# Find the GLEW package
#find_package(GLEW REQUIRED)


#set(GLEW_INCLUDE_DIR "/vendors/glew-2.2.0/include/")
set(GLEW_LIBRARIES "/vendors/glew-2.2.0/lib/")
# Adds both subdir CMakeLists.txt to the build
#add_subdirectory(vendors/glew-2.2.0)
add_subdirectory(CoffeeCupEngine)
add_subdirectory(ExampleGame)