cmake_minimum_required(VERSION 3.10)
project(Planetarium)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES src/main.cpp src/config.cpp src/program.cpp src/shader.cpp src/io.cpp src/buffer.cpp src/varray.cpp src/texture.cpp lib/glad/glad.c)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include lib/glad/include)

find_package(OpenGL REQUIRED)
if(NOT OpenGL_FOUND)
    message(FATAL_ERROR "OpenGL not found")
endif()

find_package(glfw3 REQUIRED)
if(NOT glfw3_FOUND)
    message(FATAL_ERROR "GLFW not found")
endif()

target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw)

set_target_properties(${PROJECT_NAME} PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Debug")
