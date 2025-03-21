cmake_minimum_required(VERSION 3.28)
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

option(GFMENGINE_GENERATE_VSCODE "Generate VSCode configuration files" ON)
option(GFMENGINE_GENERATE_DOCKER_SCRIPT "Generate Docker build script" ON)

if(GFMENGINE_GENERATE_VSCODE)
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
endif()

if(GFMENGINE_GENERATE_DOCKER_SCRIPT)
    configure_file(
        ${CMAKE_SOURCE_DIR}/cmake/build-using-docker.sh.in
        ${CMAKE_SOURCE_DIR}/build-using-docker.sh
        @ONLY
    )
    file(CHMOD ${CMAKE_SOURCE_DIR}/build-using-docker.sh PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
endif()
