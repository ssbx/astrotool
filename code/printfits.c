#include <stdio.h>
#include <fitswcs.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Print table content of a fits file
 */
int
main(int argc, char** argv) {
    char * file;
    if (argc < 2)
        return EXIT_FAILURE;

    file = argv[1];
    /**
     * This is where i read a fits file (with tables), and print
     * informations on every objects
     */

    /**
     * end
     */
    return EXIT_SUCCESS;
}
