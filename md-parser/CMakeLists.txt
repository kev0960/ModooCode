cmake_minimum_required(VERSION 3.0)
project(md_parser)


file(GLOB SOURCES src/*.cc src/*.h)

add_executable(md-parser ${SOURCES})
set (CMAKE_CXX_STANDARD 17)
