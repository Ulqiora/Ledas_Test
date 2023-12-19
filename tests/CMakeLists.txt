cmake_minimum_required(VERSION 3.22)

project(Tests CXX)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} tests.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC Library gtest gtest_main)

