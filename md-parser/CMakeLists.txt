cmake_minimum_required (VERSION 2.6)
project (MDParser)

# The version number.
set (MDParser_VERSION_MAJOR 1)
set (MDParser_VERSION_MINOR 0)

file(GLOB SOURCES "src/*.cc")

add_executable(mdparser ${SOURCES})
