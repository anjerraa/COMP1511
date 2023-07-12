#include <stdio.h>

void halve_values(int num_1, int num_2, int num_3);

int main(void) {
    int num_1 = 4;
    int num_2 = 10;
    int num_3 = 16;

    printf("Values before halved:\n");
    printf("Num 1: %d\n", num_1);
    printf("Num 2: %d\n", num_2);
    printf("Num 3: %d\n", num_3);

    // Since the function parameters are now pointers, you will
    // need to pass through the addresses of the corresponding
    // variables instead (using &).
    halve_values(&num_1, &num_2, &num_3);

    printf("Values after halved:\n");
    printf("Num 1: %d\n", num_1);
    printf("Num 2: %d\n", num_2);
    printf("Num 3: %d\n", num_3);

    return 0;
}

/*
The following function does not work because the num_1, num_2
and num_3 variables in the halve_values() function aren't the same
num_1, num_2 and num_3 variables in the main() function. They just
have the same values.

So when these variables are modified in halve_values(), those changes
aren't reflected back in the main() function.

Usually, if you are only modifying one variable and wanting that change
to be reflected back in the main() function, you can just return that
variable. However, in this case since you are dealing with three
variables, you can't return them because you cannot return more than
one thing.

void halve_values(int num_1, int num_2, int num_3) {
    num_1 = num_1 / 2;
    num_2 = num_2 / 2;
    num_3 = num_3 / 2;
}
*/

/*
This is where pointers are super helpful, they allow you to make changes
to multiple variables and have those changes reflected back in the main()
function.

In this case, num_1 in halve_values() will store the address of num_1 in
main(), and etc. So each of these pointers effectively point to the
corresponding ones in main().

When you deference the pointers (by putting the * in front of the pointers'
names), you are going to the address that is stored in the pointer, then
directly manipulating the value at that address. So effectively, you're
dealing with the num_1, num_2 and num_3 in main().
*/
void halve_values(int *num_1, int *num_2, int *num_3) {
    *num_1 = *num_1 / 2;
    *num_2 = *num_2 / 2;
    *num_3 = *num_3 / 2;
}