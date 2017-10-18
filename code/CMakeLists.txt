add_subdirectory(fitswcs)

add_executable(scamp2 
    main.c
    makeit.h)

include_directories(.)

target_link_libraries(scamp2 LINK_PUBLIC fitswcs)
