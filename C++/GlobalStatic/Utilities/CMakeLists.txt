
cmake_minimum_required(VERSION 3.8.1)
project(Utilities LANGUAGES CXX)

SET( CMAKE_CXX_FLAGS "-std=c++14 -Wall" )
SET( CMAKE_CXX_STANDARD 14 )


message( "========== ${PROJECT_NAME} Begin ==========")
message( "[${PROJECT_NAME}]::CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message( "[${PROJECT_NAME}]::PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message( "[${PROJECT_NAME}]::PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

file( GLOB PUBLIC_HEADER ${PROJECT_SOURCE_DIR}/Public/*.h )
aux_source_directory( ${PROJECT_SOURCE_DIR}/Private PRIVATE_SOURCE )

add_library( ${PROJECT_NAME} STATIC ${PRIVATE_SOURCE} ${PUBLIC_HEADER})

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/Public
        ${PROJECT_SOURCE_DIR}/Private
        ${PROJECT_BINARY_DIR} )

install(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION lib-static)
install(DIRECTORY Public/ DESTINATION include/Utilities FILES_MATCHING PATTERN "*.h")

message( "========== ${PROJECT_NAME} End ==========")
