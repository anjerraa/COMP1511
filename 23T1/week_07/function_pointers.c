#include <stdio.h>

void increment_time(int *days, int *hours, int *minutes);

int main(void) {
    int days = 3;
    int hours = 4;
    int minutes = 59;

    // Since the increment_time function's arguments are pointers, we need to
    // pass in the addresses of the variables we want them to point to.
    // E.g. `int *days` in increment_time will store the address of the `int days`
    // variable in the main function and so on.
    increment_time(&days, &hours, &minutes);

    printf("Current time: %d days, %d hours and %d minutes", days, hours, minutes);

    return 0;
}

// increments the time by 1 minute
void increment_time(int *days, int *hours, int *minutes) {
    // Cannot return more than 1 arguments, so if in our function we have to update
    // 3 different variables, it's best to use pointers.
    // By dereferencing these pointers, we are manipulate the values of the variables
    // that exist back in the main function.
    (*minutes)++;
    if (*minutes == 60) {
        *minutes = 0;
        (*hours)++;
    }

    if (*hours == 24) {
        *hours = 0;
        (*days)++;
    }
}