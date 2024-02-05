cmake_minimum_required(VERSION 3.10)
project(Planetarium)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES src/main.cpp lib/glad.c lib/config.cpp lib/program.cpp lib/shader.cpp lib/io.cpp lib/buffer.cpp lib/varray.cpp lib/texture.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(OpenGL REQUIRED)
if(NOT OpenGL_FOUND)
    message(FATAL_ERROR "OpenGL not found")
endif()

target_link_libraries(${PROJECT_NAME} OpenGL::GL)

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS})

find_package(glfw3 REQUIRED)
if(NOT glfw3_FOUND)
    message(FATAL_ERROR "GLFW not found")
endif()

target_link_libraries(${PROJECT_NAME} glfw)

set_target_properties(${PROJECT_NAME} PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Debug")
