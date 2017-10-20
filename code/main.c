#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief This is where we store our command line arguments
 */
struct global_args {
    int dumpconfig;
    int verbosity;
    int numInputFiles;
    char **inputFiles;
} GLOBAL_ARGS; 

/**
 * @brief print command line options
 */
void
print_opts() {
    int i;
    printf("Verbose option: %i\n", GLOBAL_ARGS.verbosity);
    printf("Dumpconfig option: %i\n", GLOBAL_ARGS.dumpconfig);

    if (GLOBAL_ARGS.numInputFiles > 0) {
        printf("Will handle files: ");
        for (i = 0; i < GLOBAL_ARGS.numInputFiles; i++) {
            printf("%s ", GLOBAL_ARGS.inputFiles[i]);
        }
        printf("\n");
    }
}

/**
 * @brief Our main function
 */
int
main(int argc, char** argv) {
    int opt, nthreads, tid;

    GLOBAL_ARGS.dumpconfig = 0;
    GLOBAL_ARGS.verbosity = 0;
    GLOBAL_ARGS.inputFiles = NULL;
    GLOBAL_ARGS.numInputFiles = 0;

    while ((opt = getopt(argc,argv, "vd")) != -1) {
        switch (opt)
        {
            case 'v':
                GLOBAL_ARGS.verbosity++;
                break;
            case 'd':
                GLOBAL_ARGS.dumpconfig++;
                break;
            default:
                abort(); 

        }
    }

    GLOBAL_ARGS.inputFiles = argv + optind;
    GLOBAL_ARGS.numInputFiles = argc - optind;

    print_opts();


    /*
     * Handle arguments
     */
    if (GLOBAL_ARGS.dumpconfig > 0) {
        printf("Dump config \n");
        exit(EXIT_SUCCESS);
    }

    /* OpenMP test */
    /* Fork a team of threads giving them their own copies of variables */
#pragma omp parallel private(nthreads, tid)
    {

        /* Obtain thread number */
        tid = omp_get_thread_num();
        printf("Hello World from thread = %d\n", tid);

        /* Only master thread does this */
        if (tid == 0) 
        {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }

    }  /* All threads join master thread and disband */

    return EXIT_SUCCESS;
}

