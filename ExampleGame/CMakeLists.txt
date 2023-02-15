
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/bin")
add_executable (ExampleGame src/exampleGame.cpp)

# Copy assets into build folder
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${PROJECT_SOURCE_DIR}/build)


target_link_libraries (ExampleGame LINK_PUBLIC CCEngine)

include_directories(${PROJECT_SOURCE_DIR}/CoffeeCupEngine/include)

target_include_directories(
    ExampleGame PUBLIC
    src/
)