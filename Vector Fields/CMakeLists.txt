cmake_minimum_required(VERSION 3.13) # Specify the minimum version for CMake

project(VectField)# Project's name

find_package(PkgConfig REQUIRED)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
find_package(SDL2 REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
include_directories("include") 
file(GLOB SOURCES "src/*.cc")


# Output
add_executable(sim ${SOURCES})
target_link_libraries(sim ${SDL2_LIBRARIES})

