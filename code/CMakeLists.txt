add_subdirectory(fitswcs)

add_executable(scamp2 main.c)

target_link_libraries(scamp2 LINK_PUBLIC fitswcs)
