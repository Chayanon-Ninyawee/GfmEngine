include(FetchContent)

cmake_minimum_required(VERSION 3.31)
project(GfmEngine)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# TODO: Maybe enable BUILD_DOCS later
set(BUILD_DOCS OFF CACHE BOOL "Disable building documentation" FORCE)

FetchContent_Declare(
    FLAC
    GIT_REPOSITORY https://github.com/xiph/flac.git
    GIT_TAG 1.5.0 # Use the latest stable version
)
set(INSTALL_MANPAGES OFF CACHE BOOL "" FORCE) # Disable manpages to avoid Pandoc error
FetchContent_MakeAvailable(FLAC)

set(SFML_USE_SYSTEM_DEPS OFF CACHE BOOL "" FORCE)
set(SFML_FIND_FLAC OFF CACHE BOOL "" FORCE)
set(AUDIO_FLAC ON CACHE BOOL "" FORCE)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
)
FetchContent_MakeAvailable(SFML)

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