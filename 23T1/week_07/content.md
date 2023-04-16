# Week 07

### 💕 Checking in

---

![Untitled](images/Untitled.png)

- How was flexi week?
- How did you find Assignment 1?
- Have you learned anything useful to take with you into Assignment 2?

### 👉🏻👈🏻 ****Part 1: The parts of a pointer****

---

In this section, we will go over a short revision section on pointers, and then walk through a demonstration simulating how pointers manipulate memory.

Revision:

- Creating a pointer,
- Getting the address of a variable,
- Accessing memory via a pointer.

### 👉🏻 ****Part 2: Coding with functions and pointers****

---

Have a quick look at the following code:

```c
#include <stdio.h>

void increment_time(int days, int hours, int minutes);

int main(void) {
    int days = 3;
    int hours = 4;
    int minutes = 59;

    increment_time(days, hours, minutes);

    printf("Current time: %d days, %d hours and %d minutes", days, hours, minutes);

    return 0;
}

// increments the time by 1 minute
void increment_time(int days, int hours, int minutes) {
    minutes++;
    if (minutes == 60) {
        minutes = 0;
        hours++;
    }

    if (hours == 24) {
        hours = 0;
        days++;
    }
}
```

Note that function `increment_time` doesn't seem to be working correctly.

- Why does it not work correctly?
- What would we need to change?

### 📦 Part 3: Struct pointers

---

Have a quick look at the following code which is slightly different from part 2 using a struct:

```c
#include <stdio.h>

struct time {
    int days;
    int hours;
    int minutes;
};

void increment_time(struct time current_time);

int main(void) {

    struct time current_time;
    current_time.days = 3;
    current_time.hours = 4;
    current_time.minutes = 59;

    increment_time(current_time);

    printf("Current time: %d days, %d hours and %d minutes", 
        current_time.days, current_time.hours, current_time.minutes);

    return 0;
}

// increments the time by 1 minute
void increment_time(struct time current_time) {
    current_time.minutes++;
    if (current_time.minutes == 60) {
        current_time.minutes = 0;
        current_time.hours++;
    }

    if (current_time.hours == 24) {
        current_time.hours = 0;
        current_time.days++;
    }
}
```

Note that function `increment_time` in this example also doesn't seem to be working correctly.

- Why does it not work correctly?
- What would we need to change?

### 🍱 Part 4: Malloc and arrays

---

In this section we'll have a look at how we can create arrays using malloc.

- What differences are there to creating an array using malloc vs no malloc?
    
    <aside>
    ☝🏻 *Using malloc*:
    
    - dynamically choosing the size of our array.
    - eventually we can decide to change the size of our array if we want to too.
    - we can safely return a pointer towards the variable from a function.
    
    *Not using malloc*:
    
    - simpler to use.
    - we don't need to worry about free().
    </aside>
    

### 🔁 ****Part 5: EOF Loops****

---

In this section, you'll be revising the different ways we can read input until EOF.

This is a piece of code that allows us to scan in a character by character.

```c
#include <stdio.h>

#define MAX_LETTERS 100

int main (void) {

    char my_var;
    while (scanf(" %c", &my_var) == 1) {
        printf("Input: %c\n", my_var);
    }

    return 0;
}
```

How can we change it to scanning in line by line instead?