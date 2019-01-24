
cmake_minimum_required(VERSION 3.8.0)
project(Utilities LANGUAGES CXX)

message( "========== ${PROJECT_NAME} Begin ==========")
message( "[${PROJECT_NAME}]::CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message( "[${PROJECT_NAME}]::PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message( "[${PROJECT_NAME}]::PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

file( GLOB PUBLIC_HEADER ${PROJECT_SOURCE_DIR}/Public/*.h )

aux_source_directory( ${PROJECT_SOURCE_DIR}/Private PRIVATE_SOURCE )

add_library( ${PROJECT_NAME} STATIC ${PRIVATE_SOURCE} ${PUBLIC_HEADER} )



target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Public
    ${PROJECT_SOURCE_DIR}/Private )

install(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION lib-static)

message( "========== ${PROJECT_NAME} End ==========")
