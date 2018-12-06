cmake_minimum_required(VERSION 3.5)
project(algo-visual)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES ./src/main.cc)

add_executable(algo-visual ${SOURCE_FILES})
add_definitions(-DMAGICKCORE_QUANTUM_DEPTH=16)
add_definitions(-DMAGICKCORE_HDRI_ENABLE=0)

find_package(ImageMagick COMPONENTS Magick++)
include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_libraries(algo-visual ${ImageMagick_LIBRARIES})
