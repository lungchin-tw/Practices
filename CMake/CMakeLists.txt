# Practice CMake

cmake_minimum_required(VERSION 3.0.0)

project(CMakePractice LANGUAGES CXX)

# define in CMakeConfig.h.in == BEGIN
set(VERSION_MAJOR "0")
set(VERSION_MINOR "1")
set(VERSION_PATCH "0")
# define in CMakeConfig.h.in == END

set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR} )

message( "CMake Begin == Project ${PROJECT_NAME} ==") 
message( "CMake Version: ${CMAKE_VERSION}") 
message( "CMake Source Dir: ${CMAKE_SOURCE_DIR}") 
message( "CMake Current Source Dir: ${CMAKE_CURRENT_SOURCE_DIR}")
message( "CMake Binary Dir: ${CMAKE_BINARY_DIR}") 
message( "CMake Current Binary Dir: ${CMAKE_CURRENT_BINARY_DIR}")
message( "CMake Install Prefix: ${CMAKE_INSTALL_PREFIX}")
message( "Project Source Dir: ${PROJECT_SOURCE_DIR}")
message( "Project Binary Dir: ${PROJECT_BINARY_DIR}")
message( "Project Version: ${VERSION}")
message( "Path: $ENV{PATH}")

add_subdirectory(src)
add_subdirectory(external)

message( "CMake End == Project ${PROJECT_NAME} ==") 