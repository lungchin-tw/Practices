cmake_minimum_required(VERSION 3.0.0)

set( CMAKE_CXX_STANDARD 11 )
set( PROJECT CMakePractice )

project( ${PROJECT} LANGUAGES CXX VERSION 0.0.0 )

message( "Cmake Current Source Path: ${CMAKE_CURRENT_SOURCE_DIR}")
message( "Project Name: ${PROJECT_NAME}")
message( "Project Binary Path: ${PROJECT_BINARY_DIR}")
message( "Project Source Path: ${PROJECT_SOURCE_DIR}")