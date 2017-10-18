add_subdirectory(fits)
add_subdirectory(wcs)
add_library(fitswcs
        fitswcs.c
        fitswcs.h
        wcscelsys.h
        )

target_link_libraries(fitswcs LINK_PUBLIC fits wcs -lm)
target_include_directories(fitswcs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


