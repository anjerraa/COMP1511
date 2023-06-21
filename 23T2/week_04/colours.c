#include <stdio.h>
#include <math.h>

struct colour {
    int red;
    int green;
    int blue;
};

struct colour make_colour(int red, int green, int blue);
int get_main_colour(struct colour c);
double brightness(struct colour colour);
double average_brightness(struct colour colours[100], int size);

int main(void) {
    /*
        In calling the `make_colour` function, we need to give it
        arguments which correspond to the amount of red/blue/green
        we want to put into the colour.
        The order of the arguments is important...
        -> 10 will be considered as red
        -> 5 will be considered as green
        -> 2 will be considered as blue

        Since `make_colour` function returns a type of `struct colour`,
        we want to capture the return value into our own `struct colour`
        in the main function.

        Note that the name of the `struct colour` in the `main` function
        does not need to match the one returned in the `make_colour`
        function because they aren't the same `struct colour`, they will
        just have the same values.
    */
	struct colour colour = make_colour(10, 5, 2);
}

struct colour make_colour(int red, int green, int blue) {
    struct colour new_colour;

    new_colour.red = red;
    new_colour.green = green;
    new_colour.blue = blue;

    return new_colour;
}

int get_main_colour(struct colour c) {
    if (c.red > c.green && c.red > c.blue) {
        return c.red;
    } else if (c.green > c.red && c.green > c.blue) {
        return c.green;
    } else if (c.blue > c.red && c.blue > c.green) {
        return c.blue;
    } else {
        return 0;
    }
}

double brightness(struct colour colour) {
    return sqrt(colour.red) + sqrt(colour.green) + sqrt(colour.blue);
}

double average_brightness(struct colour colours[100], int size) {
    double sum = 0;

    int i = 0;
    while (i < size) {
        sum += brightness(colours[i]);
        i++;
    }

    return sum / size;
}