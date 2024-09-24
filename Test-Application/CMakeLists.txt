cmake_minimum_required(VERSION 3.30.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

project(TestApp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

set(SRC_DIRS
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/../GridGL-engine/src
)

set(SRC_FILES)

foreach(dir ${SRC_DIRS})
    file(GLOB_RECURSE CPP_FILES "${dir}/*.cpp")
    list(APPEND SRC_FILES ${CPP_FILES})
endforeach()

message(SRC_FILES="${SRC_FILES}")

add_executable("${PROJECT_NAME}" ${SRC_FILES})
target_include_directories("${PROJECT_NAME}" PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/dependencies/include"
    "${PROJECT_SOURCE_DIR}/../GridGL-engine/dependencies/include"
    "${PROJECT_SOURCE_DIR}/../GridGL-engine/src"
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

