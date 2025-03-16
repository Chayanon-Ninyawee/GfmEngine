cmake_minimum_required(VERSION 3.31)
project(GfmEngineTest)

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${TEST_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE GfmEngine)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set(EXECUTABLE_NAME ${PROJECT_NAME})

# Generate launch.json for debugging
configure_file(
    ${CMAKE_SOURCE_DIR}/cmake/launch.json.in
    ${CMAKE_SOURCE_DIR}/.vscode/launch.json
    @ONLY
)

# Generate tasks.json for building before running
configure_file(
    ${CMAKE_SOURCE_DIR}/cmake/tasks.json.in
    ${CMAKE_SOURCE_DIR}/.vscode/tasks.json
    @ONLY
)
