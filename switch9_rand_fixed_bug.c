#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sodium.h>

enum D6Result
{
    D6RESULT_ONE = 1,
    D6RESULT_TWO,
    D6RESULT_THREE,
    D6RESULT_FOUR,
    D6RESULT_FIVE,
    D6RESULT_SIX
};

enum D6Result roll_d6()
{
    return (enum D6Result)(1 + randombytes_uniform(6));
}

int main()
{
    enum D6Result result;

    if (sodium_init() < 0) {
        fprintf(stderr, "Failed sodium_init()\n");
        return EXIT_FAILURE;
    }

    result = roll_d6();

    switch (result) {
        case D6RESULT_ONE:
            {
                printf("Half of a Snake Eyes...\n");
                printf("You got a one\n");
                break;
            }
        case D6RESULT_TWO:
        case D6RESULT_THREE:
        case D6RESULT_FOUR:
        case D6RESULT_FIVE:
            {
                printf("You got a %i\n", result);
                break;
            }
        case D6RESULT_SIX:
            {
                printf("Critical!!!\n");
                printf("You got a six\n");
                break;
            }
    }

    return EXIT_SUCCESS;
}
