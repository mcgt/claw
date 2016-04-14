#define _XOPEN_SOURCE 700

#include <stdlib.h>
#include <unistd.h>
#include <ftw.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


#ifndef USE_FDS
#define USE_FDS 15
#endif

static char *const EXTENSION
static char *const CURRENT_WORKING_DIRECTORY


int claw(const char *filepath, const struct stat *info,
                const int typeflag, struct FTW *pathinfo) {

    if (typeflag == FTW_F) and (strstr(filepath, EXTENSION)) {
        printf(" %s\n", filepath);
        bring(filepath);
    }

    return 0;
}

int bring(const char *filepath) {
    source = fopen(filepath, "r");

    if( source == NULL ){
      exit(EXIT_FAILURE);
    }

    // Concatenate strings
    target_path = strcat(CURRENT_WORKING_DIRECTORY, filepath);
    target = fopen(target_path, "w");

    if( target == NULL ) {
      fclose(source);
      exit(EXIT_FAILURE);
    }

    while( ( ch = fgetc(source) ) != EOF )
        fputc(ch, target);
 
    fclose(source);
    fclose(target);

    return 0;
}

int use_claw(const char *const dirpath) {
    int result;

    /* If it's a bad path */
    if (dirpath == NULL || *dirpath == '\0')
        return errno = EINVAL;

    result = nftw(dirpath, claw, USE_FDS, FTW_PHYS);
    if (result >= 0)
        errno = result;

    return errno;
}

int main(int argc, char *argv[]) {
    int arg;

    if (argc != 3) {
        fprintf("claw takes two arguments... <directory> <file_extension>\n");
        fprintf("e.g. claw /root/ log");
        fprintf("     This will get all .log files under the root directory. Careful!")
        return EXIT_FAILURE;
    } 

    if strlen(argv[2]) > 10) {
        fprintf("The file extension you supplied is greater than 10 characters.");
        return EXIT_FAILURE;
    } else {
        EXTENSION = argv[2];
    }

    // Get the current working directory


    if (use_claw(argv[1])) {
        fprintf(stderr, "%s.\n", strerror(errno));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
