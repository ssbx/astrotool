add_library(fits
        fitsbody.c
        fitscat.c
        fitscat.h
        fitscat_defs.h
        fitscheck.c
        fitscleanup.c
        fitsconv.c
        fitshead.c
        fitskey.c
        fitsmisc.c
        fitsread.c
        fitstab.c
        fitsutil.c
        fitswrite.c
        )

add_definitions(-DHAVE_SYS_MMAN_H)
target_include_directories(fits PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

