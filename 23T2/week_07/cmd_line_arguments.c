#include <stdio.h>

int main(int argc, char *argv[]) {
    
    // argc is argument count -> how many command line arguments
    // you get (including the program name).
    printf("argc is: %d\n", argc);

    // argv is argument vector -> it is just an array of command
    // line arguments (strings).
    printf("argv are:\n");
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}