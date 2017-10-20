cmake_minimum_required(VERSION 2.8)
project(scamp2)
enable_language(C)

add_subdirectory(deps)
add_subdirectory(code)

enable_testing()
add_test (NAME step1 COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tests/step1.sh)
