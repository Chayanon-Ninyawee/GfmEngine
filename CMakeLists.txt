include(FetchContent)

cmake_minimum_required(VERSION 3.28)
project(GfmEngine)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(SFML_USE_STATIC_STD_LIBS ON CACHE BOOL "" FORCE) # Ensure SFML is built with static standard libs
add_subdirectory(external/SFML)

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE ENGINE_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

add_library(${PROJECT_NAME} STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    sfml-graphics sfml-window sfml-system
)

# Add a test executable (Optional: Enable only when testing)
option(BUILD_ENGINE_TESTS "Build the engine test executable" ON)

if(BUILD_ENGINE_TESTS)
    add_subdirectory(test)
endif()