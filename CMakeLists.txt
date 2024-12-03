cmake_minimum_required(VERSION 3.29)
project(cpptemplate)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)


add_library(lib STATIC src/Application.cpp)

add_executable(cpptemplate main.cpp)
target_link_libraries(cpptemplate lib)

include_directories(lib/spdlog)
include_directories(src)

add_subdirectory(tests)
