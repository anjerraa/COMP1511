#include <stdio.h>

#define MAX_LETTERS 100

int main (void) {

    // Scanning in char by char until Ctrl+D
    char my_var;
    while (scanf(" %c", &my_var) == 1) {
        printf("Input: %c\n", my_var);
    }

    // Scanning in line by line until Ctrl+D
    char str[MAX_LETTERS];
    // fgets returns NULL if user Ctrl+D, so we want to
    // continuously scan while fgets doesn't return NULL
    while (fgets(str, MAX_LETTERS, stdin) != NULL) {
        printf("my string is: %s\n", str);
    }

    return 0;
}