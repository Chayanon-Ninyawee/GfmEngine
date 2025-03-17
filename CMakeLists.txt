include(FetchContent)

cmake_minimum_required(VERSION 3.28)
project(GfmEngine)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# TODO: Maybe enable BUILD_DOCS later
set(BUILD_DOCS OFF CACHE BOOL "Disable building documentation" FORCE)

# set(BUILD_SHARED_LIBS OFF) # Force SFML to build statically
# set(SFML_USE_STATIC_STD_LIBS ON CACHE BOOL "" FORCE) # Ensure SFML is built with static standard libs
add_subdirectory(external/SFML)

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${ENGINE_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    sfml-graphics sfml-window sfml-system
)

# Add a test executable (Optional: Enable only when testing)
option(BUILD_ENGINE_TESTS "Build the engine test executable" ON)

if(BUILD_ENGINE_TESTS)
    add_subdirectory(test)
endif()