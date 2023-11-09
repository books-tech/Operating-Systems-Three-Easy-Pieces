#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: mem <value>\n");
        exit(1);
    }
    int *p; // p is a pointer to an integer

    /*
     malloc(sizeof(int)) requests memory from the heap:
        - sizeof(int) typically requests 4 bytes (size of an integer)
        - malloc returns a pointer to this allocated memory block
        - If allocation fails, malloc returns NULL
    */
    // p now holds a memory address
    p = malloc(sizeof(int)); // program allocates space for one integer on the heap
    assert(p != NULL); // checks if allocation succeeded with assert(p != NULL)
    printf("(%d) addr pointed to by p: %p\n", (int) getpid(), p);

    // - Store a value converted from command line argument (atoi(argv[1]))
    // - after *p = atoi(argv[1]), that memory would contain the value 5 (or anyother value passed in terminal),
    //      which gets repeatedly incremented in the while loop
    // - '*' dereferences p: "go to the address and put 5 there"
    *p = atoi(argv[1]);
    // Continuously increment this value in the while loop
    while (1) {
        Spin(1);
        // int x = *p;  —  '*' gets the value stored at p's address
        *p = *p + 1;
        printf("(%d) value of p: %d\n", getpid(), *p);
    }
    return 0;
}
