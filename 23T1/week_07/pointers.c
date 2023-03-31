#include <stdio.h>

int main(void) {

    // Create an int variable;
    // Address 0xFF00
    int var = 2;

    // Creating an int pointer -> ptr;
    int *ptr;
    
    // Getting the address of a variable;
    ptr = &var;

    // Print the address that ptr stores;
    // Prints out 0xFF00 (which is the address of
    // var).
    printf("Address that ptr stores: %p\n", ptr);

    // Accessing memory via a pointer;
    // Prints out the value of var which is 2.
    printf("Value stored at the address in ptr: %d\n", *ptr);

    // Change the value stored at the address.
    *ptr = 22;

    printf("The value of var: %d\n", var);

    return 0;
}