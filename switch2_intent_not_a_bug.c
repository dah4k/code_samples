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

    {
        if (result == 1)
            {
                printf("Half of a Snake Eyes...\n");
                printf("You got a one\n");
            }
        else if (result == 6)
            {
                puts("Critical!!!");
                puts("You got a six");
            }
        else
            {
                printf("You got a %i\n", result);
            }
    }

    return 0;
}
