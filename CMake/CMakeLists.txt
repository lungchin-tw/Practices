cmake_minimum_required(VERSION 3.0.0)

project(CMakePractice LANGUAGES CXX)

set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_PATCH "0")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
set( CMAKE_CXX_STANDARD 11 )

message( "Cmake Current Source Path: ${CMAKE_CURRENT_SOURCE_DIR}")
message( "Project Name: ${PROJECT_NAME}")
message( "Project Version: ${VERSION}")
message( "Project Binary Path: ${PROJECT_BINARY_DIR}")
message( "Project Source Path: ${PROJECT_SOURCE_DIR}")
message( "CMake Build Type: ${CMAKE_BUILD_TYPE}")
message( "CMake Install Prefix: ${CMAKE_INSTALL_PREFIX}")
message( "CMake OSX Architectures: ${CMAKE_OSX_ARCHITECTURES}")
message( "CMake OSX Sys Root: ${CMAKE_OSX_SYSROOT}")