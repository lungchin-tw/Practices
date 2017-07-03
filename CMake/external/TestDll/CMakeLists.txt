project(TestDll)


message( "CMake Begin == Project ${PROJECT_NAME} ==" )
message( "[${PROJECT_NAME}]::CMake Source Dir: ${CMAKE_SOURCE_DIR}" )
message( "[${PROJECT_NAME}]::CMake Current Source Dir: ${CMAKE_CURRENT_SOURCE_DIR}" )
message( "[${PROJECT_NAME}]::CMake Binary Dir: ${CMAKE_BINARY_DIR}" )
message( "[${PROJECT_NAME}]::CMake Current Binary Dir: ${CMAKE_CURRENT_BINARY_DIR}" )
message( "[${PROJECT_NAME}]::CMake Install Prefix: ${CMAKE_INSTALL_PREFIX}" )
message( "[${PROJECT_NAME}]::Project Source Dir: ${PROJECT_SOURCE_DIR}")
message( "[${PROJECT_NAME}]::Project Binary Dir: ${PROJECT_BINARY_DIR}")

include_directories( ${PROJECT_SOURCE_DIR}/inc )

file(GLOB ${PROJECT_NAME}_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp )

add_library( ${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SOURCES} )

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib-static
        LIBRARY DESTINATION lib
)

install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION bin
)

message( "CMake End == Project ${PROJECT_NAME} ==" )