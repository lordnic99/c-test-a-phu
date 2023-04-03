cmake_minimum_required(VERSION 2.8)

project(test)
set(CMAKE_BUILD_TYPE Debug)
FILE(GLOB SRC "src/*.c")

add_executable(${PROJECT_NAME} ${SRC})
