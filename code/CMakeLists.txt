add_subdirectory(fitswcs)
include_directories(.)

add_executable(printfits
    printfits.c)
target_link_libraries(printfits LINK_PUBLIC fitswcs)

add_executable(crossmatch
    crossmatch.c)
target_link_libraries(crossmatch LINK_PUBLIC fitswcs)

add_executable(scamp2 
    main.c)
target_link_libraries(scamp2 LINK_PUBLIC fitswcs)


