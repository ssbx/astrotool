cmake_minimum_required(VERSION 2.8)
project(scamp2)
enable_language(C)

find_package(LAPACK REQUIRED)
set(CMAKE_EXE_LINKER_FLAGS 
    ${CMAKE_EXE_LINKER_FLAGS} 
    ${LAPACK_LINKER_FLAGS})
set(BLA_STATIC TRUE)

find_package(OpenMP REQUIRED)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS})

add_subdirectory(deps)
add_subdirectory(code)

enable_testing()
add_test (NAME step1 COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tests/step1.sh)
