#include <stdio.h>

int main(int argc, char *argv[]) {

	int i;
    for (i = 0; i < argc; ++i) {
        
    }
    claw(argv[1], argv[2]);


    return 0;
}


int claw(char start_dir[], char extension[]){

	printf(start_dir);
	printf(extension);
}