#include <stdio.h>

int main(void) {

    /*
        -> This is how to scan in inputs until user Ctrl+D
        -> The return value of scanf corresponds to how many
           values it successfully scanned in
        -> If the user gives an invalid input type or Ctrl+D,
           scanf will return 0 and -1 (respectively)
        -> If you were scanning in two things, you want to
           check if scanf returns 2 instead and so on...
    */

    char a;
    while (scanf("%c", &a) == 1) {
        printf("%c", a);
    }

    return 0;
}