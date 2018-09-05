cmake_minimum_required(VERSION 3.0)
set(PROJECT_NAME md_parser)
project(${PROJECT_NAME})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
file(GLOB SOURCES src/*.cc src/*.h)

add_library(chroma SHARED IMPORTED)
set_target_properties(chroma
                      PROPERTIES IMPORTED_LOCATION
                                 "${CMAKE_SOURCE_DIR}/lib/chroma.so")
add_executable(md-parser ${SOURCES})
target_link_libraries(md-parser chroma stdc++fs pthread)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)

if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines the gtest and gtest_main
# targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path dependencies
# automatically when using CMake 2.8.11 or later. Otherwise we have to add them
# here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories(
    "${gtest_SOURCE_DIR}/include" "${gmock_SOURCE_DIR}/include")
else()
  target_include_directories(gmock_main SYSTEM BEFORE INTERFACE
    "${gtest_SOURCE_DIR}/include" "${gmock_SOURCE_DIR}/include")
endif()

add_executable(util_test test/util_test.cc src/util.cc)
target_link_libraries(util_test gtest_main chroma)
add_test(NAME util_test COMMAND util_test)

add_executable(content_test
               test/content_test.cc
               src/content.cc
               src/util.cc
               src/content_header.cc
               src/content_list.cc
               src/parser_environment.cc)
target_link_libraries(content_test gtest_main chroma)
add_test(NAME content_test COMMAND content_test)

add_executable(parser_test
               test/parser_test.cc
               src/content.cc
               src/util.cc
               src/parser.cc
               src/content_header.cc
               src/content_list.cc
               src/parser_environment.cc)
target_link_libraries(parser_test gmock_main chroma)
add_test(NAME parser_test COMMAND parser_test)

add_executable(path_test
               test/path_test.cc
               src/util.cc
               src/path.cc)
target_link_libraries(path_test gmock_main)
add_test(NAME path_test COMMAND path_test)
