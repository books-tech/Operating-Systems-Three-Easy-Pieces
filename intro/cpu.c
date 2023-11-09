#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[])
{
	// Print the value of argc. `argc` is the command ran in terminal. It includes everything that ran in terminal
	printf("Number of arguments (argc): %d\n", argc); // for `./cpu`, will print 1 || for `./cpu A`, will print 2

    if (argc != 2) {
	fprintf(stderr, "usage: cpu <string>\n");
	exit(1);
    }
    char *str = argv[1];

    while (1) {
	printf("%s\n", str);
	Spin(1);
    }
    return 0;
}

