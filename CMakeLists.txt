cmake_minimum_required(VERSION 3.10)
project(Planetarium)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES src/main.cpp lib/glad.c)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS})

find_package(glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)

set_target_properties(${PROJECT_NAME} PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Debug")
