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

# Adds both subdir CMakeLists.txt to the build
add_subdirectory(vendors/glew)
add_subdirectory(CoffeeCupEngine)
add_subdirectory(ExampleGame)