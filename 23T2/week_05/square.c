#include <stdio.h>

#define SIZE 100

// We use a pointer to not have to return a value
void square(int *x) {
    *x = *x * *x;
}

// Alternatively,
/*
int square(int x) {
    return x * x;
}
*/

// Arrays are pointers themselves so you do not need
// to explicitly return array when you modify them in
// a function
void square_array(int array[SIZE], int length) {
    for (int i = 0; i < length; i++) {
        array[i] = array[i] * array[i];
    }
}

int main(void) {

    int a = 10;
    square(&a);
    // Alternatively,
    // a = square(a);
    printf("The squared value is: %d\n", a);

    int length = 5;
    int array[SIZE] = {1, 2, 3, 4, 5};
    square_array(array, length);

    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}