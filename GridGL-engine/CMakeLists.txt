cmake_minimum_required(VERSION 3.30.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

project(GridGL)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library("${PROJECT_NAME}" ${SRC_FILES})
target_include_directories("${PROJECT_NAME}" PRIVATE
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/dependencies/include"
)

add_library(glad STATIC "${PROJECT_SOURCE_DIR}/../GridGl-engine/dependencies/library/glad.c")
target_include_directories(glad PRIVATE "${PROJECT_SOURCE_DIR}/../GridGl-engine/dependencies/include")

target_link_libraries("${PROJECT_NAME}" OpenGL::GL
    glfw
    glad)

# copy shader files to final build folder
#add_custom_target(
#    copy_shaders ALL
#    COMMAND ${CMAKE_COMMAND} -E copy_directory
#    ${PROJECT_SOURCE_DIR}/src/shaders
#    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shaders
#)
#
#set_target_properties(copy_shaders PROPERTIES
#    ADDITIONAL_CLEAN_FILES ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shaders
#)

