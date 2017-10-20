cmake_minimum_required(VERSION 2.8)
project(dance)
enable_language(C)

find_package(LAPACK REQUIRED)
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LAPACK_LINKER_FLAGS}")
set(BLA_STATIC TRUE)

find_package(MPI)
if (MPI_C_FOUND)
    add_definitions(-D_WITH_MPI)
    include_directories(${MPI_C_INCLUDE_PATH})
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MPI_C_LINK_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MPI_C_COMPILE_FLAGS}")
endif (MPI_C_FOUND)

find_package(OpenMP REQUIRED)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")

add_subdirectory(deps)
add_subdirectory(code)

enable_testing()
add_test (NAME step1 COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tests/step1.sh)
