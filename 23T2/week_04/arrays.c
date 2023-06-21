#include <stdio.h>

#define SIZE 5

// Function prototypes since these functions
// exist after the main function.
void odd_only(void);
void copy_array(void);

int main(void) {
    
    odd_only();
    copy_array();
    
    return 0;
}

void odd_only(void) {
    int array[SIZE] = {1, 2, 3, 4, 5};

    int i = 0;
    while (i < SIZE) {
        if (array[i] % 2 == 0) {
            array[i]++;
        }
        i++;
    }

    int j = 0;
    while (j < SIZE) {
        printf("%d ", array[j]);
        j++;
    }
    printf("\n");
}

void copy_array(void) {
    // Probably should #define these sizes but
    // I'm lazy :Ps
    double array_1[3] = {0.1, 4.9, 3.5};
    double array_2[10] = {0};

    int i = 0;
    while (i < 3) {
        array_2[i] = array_1[i];
        i++;
    }

    int j = 0;
    while (j < 10) {
        printf("%lf ", array_2[j]);
        j++;
    }
    printf("\n");
}

