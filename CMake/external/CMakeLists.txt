project(external)

message( "CMake Begin == Project ${PROJECT_NAME} ==" )
message( "CMake Source Dir: ${CMAKE_SOURCE_DIR}" )
message( "CMake Current Source Dir: ${CMAKE_CURRENT_SOURCE_DIR}" )
message( "CMake Binary Dir: ${CMAKE_BINARY_DIR}" )
message( "CMake Current Binary Dir: ${CMAKE_CURRENT_BINARY_DIR}" )
message( "Project Source Dir: ${PROJECT_SOURCE_DIR}")
message( "Project Binary Dir: ${PROJECT_BINARY_DIR}")

add_subdirectory(TestDll)

message( "CMake End == Project ${PROJECT_NAME} ==" )