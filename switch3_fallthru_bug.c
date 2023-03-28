#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_biased_d6()
{
    return (rand() % 6) + 1;
}

int main()
{
    int result;

    srand(time(NULL));
    result = roll_biased_d6();

    switch (result) {
        case 1:
            printf("Half of a Snake Eyes...\n");
            printf("You got a one\n");
        case 6:
            puts("Critical!!!");
            puts("You got a six");
        default:
            printf("You got a %i\n", result);
    }

    return 0;
}
