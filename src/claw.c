#include <stdio.h>

int main(int argc, char *argv[]) {


    // if helptext in argv[1] print 1
    if (argc == 2) {
        if (strcmp(argv[1], "--h") == 0 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h")) {
            printf("\n./claw <search_directory> <file_extension>\n");

        }
    }

    // if length of argv less than three
    // print out help message


    // if length of argv is greater than 3
    // too many arguments

    // validate
    // if validate returns false
    // exit



    claw(argv[1], argv[2]);


    return 0;
}


int claw(char start_dir[], char extension[]){

	//printf(start_dir);
	//printf(extension);
}