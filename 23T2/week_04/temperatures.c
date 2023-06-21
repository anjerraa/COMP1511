#include <stdio.h>

#define NUM_DAYS 7

int main(void) {

    double temperatures[NUM_DAYS];
    int i = 0;
    while (i < NUM_DAYS) {
        scanf("%lf", &temperatures[i]);
        i++;
    }

    double highest_temperature = temperatures[0];

    int j = 0;
    while (j < NUM_DAYS) {
        if (highest_temperature < temperatures[j]) {
            highest_temperature = temperatures[j];
        }
        j++;
    }

    printf("The highest temperature is: %lf\n", highest_temperature);

    return 0;
}