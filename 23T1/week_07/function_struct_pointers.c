#include <stdio.h>

struct time {
    int days;
    int hours;
    int minutes;
};

// // Option A: make the function return the updated `struct time current_time`:
// struct time increment_time(struct time current_time);

// Option B: make the function takes in a pointer to a type `struct time`:
void increment_time(struct time *current_time);

int main(void) {

    struct time current_time;
    current_time.days = 3;
    current_time.hours = 4;
    current_time.minutes = 59;

    // // Option A: make the function return the updated `struct time current_time`:
    // current_time = increment_time(current_time);

    // Option B: make the function takes in a pointer to a type `struct time`:
    increment_time(&current_time);

    printf("Current time: %d days, %d hours and %d minutes", 
        current_time.days, current_time.hours, current_time.minutes);

    return 0;
}

// There are two valid ways of making the program work:

// // Option A: make the function return the updated `struct time current_time`:
// struct time increment_time(struct time current_time) {
//     current_time.minutes++;
//     if (current_time.minutes == 60) {
//         current_time.minutes = 0;
//         current_time.hours++;
//     }

//     if (current_time.hours == 24) {
//         current_time.hours = 0;
//         current_time.days++;
//     }
//     return current_time;
// }

// Option B: make the function takes in a pointer to a type `struct time`:
void increment_time(struct time *current_time) {
    // Need to dereference the `current_time` pointer first to get the struct
    // time that exists at the address, before you can access its field.
    // (*current_time).minutes++;
    current_time->minutes++; // The same as the line above, but more concise
    // The stab notation `->` effectively dereferences the struct pointer 
    // and access its field at the same time
    if (current_time->minutes == 60) {
        current_time->minutes = 0;
        current_time->hours++;
    }

    if (current_time->hours == 24) {
        current_time->hours = 0;
        current_time->days++;
    }
}