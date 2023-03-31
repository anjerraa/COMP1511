#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct time {
    int days;
    int hours;
    int minutes;
};

int main(void) {

    // Malloc takes in the number of bytes that you want to
    // allocate memory for, and returns the address to the piece
    // of memory that it just made.
    // Need to store the address into a pointer.

    // Instead of writing out how many bytes you need, you should
    // use `sizeof()` to get the size of a variable in bytes.
    // When allocating memory for an array, you need to allocate
    // enough memory, thus times the size of each element in the array
    // by the array size.

    // This is to create an array of ints
    int *int_array = malloc(sizeof(int) * SIZE);

    // This is to create an array of doubles
    double *double_array = malloc(sizeof(double) * SIZE);

    // This is to create an array of chars
    char *char_array = malloc(sizeof(char) * SIZE);

    // This is to create an array of `struct time`
    struct time *struct_time_array = malloc(sizeof(struct time) * SIZE);

    // Thus, note that the pointer type and sizeof() need to be changed 
    // according to the type of each element in the array!!!

    return 0;
}