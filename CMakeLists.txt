cmake_minimum_required(VERSION 3.21)
project(LoginSystem)
set(CMAKE_CXX_STANDARD 17)

# Set the build output location to a common directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(OpenXLSX)
add_executable(LoginSystem Main.cpp LoginSystem.cpp LoginSystem.h generalFunctions.cpp Database.cpp Database.h  generalFunctions.h)
target_link_libraries(LoginSystem OpenXLSX::OpenXLSX)
