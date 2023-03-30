#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum D6Result
{
    ONE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX
};

enum D6Result roll_biased_d6()
{
    return (enum D6Result)(42);
}

int main()
{
    enum D6Result result;

    srand(time(NULL));
    result = roll_biased_d6();

    switch (result) {
        case ONE:
            {
                printf("Half of a Snake Eyes...\n");
                printf("You got a one\n");
                break;
            }
        case TWO:
        case THREE:
        case FOUR:
        case FIVE:
            {
                printf("You got a %i\n", result);
                break;
            }
        case SIX:
            {
                puts("Critical!!!");
                puts("You got a six");
                break;
            }
    }

    return EXIT_SUCCESS;
}
