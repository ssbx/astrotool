add_library(wcs
        cel.c
        cel.h
        lin.c
        lin.h
        poly.c
        poly.h
        proj.c
        proj.h
        sph.c
        sph.h
        tnx.c
        tnx.h
        wcs.c
        wcs.h
        wcsmath.h
        wcstrig.c
        wcstrig.h
        )

target_include_directories(wcs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

