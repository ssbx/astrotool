#include <stdio.h>
#include <fitswcs.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct scamp_args {
    int dumpconfig;
    int verbosity;
    int numInputFiles;
    char **inputFiles;
} ScampArgs; 

ScampArgs GLOBAL_ARGS;;

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

int
main(int argc, char** argv) {
    int aflag = 0, bflag = 0, dumplevel = 0, index, c;
    char *cvalue = NULL;

    GLOBAL_ARGS.dumpconfig = 0;
    GLOBAL_ARGS.verbosity = 0;
    GLOBAL_ARGS.inputFiles = NULL;
    GLOBAL_ARGS.numInputFiles = 0;

    while ((c = getopt(argc,argv, "vd")) != -1) {
        switch (c)
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

    return 0;
}
