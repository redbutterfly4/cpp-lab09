cmake_minimum_required(VERSION 3.29)
project(lab09)

set(CMAKE_CXX_STANDARD 20)
enable_testing()



add_library(lib STATIC src/Application.cpp src/NodeStack.h src/StackOnList.h src/StackOnArray.h)

add_executable(cpptemplate main.cpp)
target_link_libraries(cpptemplate lib)

include_directories(lib/spdlog)
add_subdirectory(lib)
include_directories(src)

add_subdirectory(tests)
