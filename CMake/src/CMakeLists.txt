project(CMakePracticeExe)

include_directories(${PROJECT_BINARY_DIR})

configure_file(
    ${PROJECT_SOURCE_DIR}/CMakeConfig.h.in
    ${PROJECT_BINARY_DIR}/CMakeConfig.h
)

message( "CMake Begin == Project ${PROJECT_NAME} ==" )
message( "CMake Source Dir: ${CMAKE_SOURCE_DIR}" )
message( "CMake Current Source Dir: ${CMAKE_CURRENT_SOURCE_DIR}" )
message( "CMake Binary Dir: ${CMAKE_BINARY_DIR}" )
message( "CMake Current Binary Dir: ${CMAKE_CURRENT_BINARY_DIR}" )

add_executable( ${PROJECT_NAME} main.cpp )

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
)

message( "CMake End == Project ${PROJECT_NAME} ==" )