cmake_minimum_required(VERSION 3.22)
project(project CXX)
set(CMAKE_CXX_STANDARD 20)
add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(library)

target_link_libraries(${PROJECT_NAME} PUBLIC Library)