#include <stdio.h>
#include <fitswcs.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * @brief Our main function
 */
int
main(int argc, char** argv) {
    char *file1, *file2;

    if (argc < 3)
        return EXIT_FAILURE;

    file1 = argv[1];
    file2 = argv[2];

    /**
     * This is here, take two fits table data and cross match every
     * objects.
     */

    /**
     * end
     */

    return EXIT_SUCCESS;
}
