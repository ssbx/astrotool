include_directories(
    .
    ${FITS_INCLUDES}
)

if (MPI_C_FOUND)
    include_directories(${MPI_C_INCLUDE_PATH})
    add_executable(mainmpi
        main_mpi.c)
    target_link_libraries(mainmpi
        ${MPI_C_LIBRARIES})
endif (MPI_C_FOUND)

add_executable(scamp2
 main.c)
target_link_libraries(scamp2 
        ${LAPACK_LIBRARIES}
        ${FITS_LIBRARIES})

add_executable(step1_printFitsTable
    step1_printFitsTable.c)
target_link_libraries(step1_printFitsTable fits)

add_executable(step2_getGaiaObjects
    step2_getGaiaObjects.c)
target_link_libraries(step2_getGaiaObjects fits)

add_executable(step3_crossMatchTables
    step3_crossMatchTables.c)
target_link_libraries(step3_crossMatchTables fits)

add_executable(step4_resolveAstroSolution
 step4_resolveAstroSolution.c)
target_link_libraries(step4_resolveAstroSolution fits)


