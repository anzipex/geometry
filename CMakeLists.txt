cmake_minimum_required(VERSION 3.13)
project(geometry)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)

add_executable(geometry main.cpp Object.cpp Parser.cpp)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)

add_dependencies(geometry OpenGL::OpenGL)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(geometry ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
