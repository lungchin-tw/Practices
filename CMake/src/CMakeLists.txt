project(CMakePracticeExe)

file(GLOB_RECURSE WORKSPACE_HEADERS ${PROJECT_SOURCE_DIR}/inc/*.h )

include_directories(${PROJECT_BINARY_DIR} ${WORKSPACE_HEADERS})

configure_file(
    ${PROJECT_SOURCE_DIR}/CMakeConfig.h.in
    ${PROJECT_BINARY_DIR}/CMakeConfig.h
)

message( "CMake Begin == Project ${PROJECT_NAME} ==" )
message( "CMake Source Dir: ${CMAKE_SOURCE_DIR}" )
message( "CMake Current Source Dir: ${CMAKE_CURRENT_SOURCE_DIR}" )
message( "CMake Binary Dir: ${CMAKE_BINARY_DIR}" )
message( "CMake Current Binary Dir: ${CMAKE_CURRENT_BINARY_DIR}" )
message( "Project Source Dir: ${PROJECT_SOURCE_DIR}")
message( "Project Binary Dir: ${PROJECT_BINARY_DIR}")

##SET(CMAKE_SKIP_BUILD_RPATH FALSE)
##SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib" )
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_executable( ${PROJECT_NAME} main.cpp )

target_link_libraries(${PROJECT_NAME} TestLib TestDll)

add_subdirectory(TestLib)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib-static
        LIBRARY DESTINATION bin
)

message( "CMake End == Project ${PROJECT_NAME} ==" )