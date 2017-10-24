include_directories(
    .
    ${FITS_INCLUDES}
)

add_executable(scamp
     main.c)
target_link_libraries(scamp 
        ${LAPACK_LIBRARIES}
        ${FITS_LIBRARIES})

add_executable(mainopenmp main_openmp.c)

