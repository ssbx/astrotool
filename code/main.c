#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct s {
    int hello;
};

struct field {
    struct s **set;
    int nset;
};

void testarray() {
    int a[10];
    int *pa;
    pa = &a;
    int i;
    for (i=0; i<10; i++) {
        a[i] = i;
    }
    for (i=0; i<10; i++) {
        printf("hello %i\n", pa[i]);
    }
}

void testloop() {
    struct s s1;
    struct s s2;
    struct s s3;
    struct s s4;
    s1.hello = 1;
    s2.hello = 2;
    s3.hello = 3;
    s4.hello = 4;
    int numset = 4, s;
    struct s *g;

    struct field f;
    f.set = malloc(4 * sizeof(&s1));
    f.set[0] = &s1;
    f.set[1] = &s2;
    f.set[2] = &s3;
    f.set[3] = &s4;
    f.nset = 4;

    int i = 4;
    struct s *l;
    for(; i && (f.set++); i--) {
        printf("arghhhh %i\n", f.set[0]->hello);
    }
}

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
    int opt;

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


    if (4 < 5) {
        printf("hhhhhhhhhokkkkkkkkkk\n");
    }

    return EXIT_SUCCESS;
}

