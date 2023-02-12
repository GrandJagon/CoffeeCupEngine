set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_executable (GameExample src/gameExample.cpp)

target_link_libraries (GameExample LINK_PUBLIC CCEngine)

target_include_directories(
    GameExample PUBLIC
    src/
)