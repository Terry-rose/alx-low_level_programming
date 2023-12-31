#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int n, lastDigit;

    srand(time(0));
    n = rand() - RAND_MAX / 2;
    lastDigit = abs(n) % 10; /*Calculate the last digit (use abs() to handle negative numbers)*/

    printf("Last digit of %d is %d and is ", n, lastDigit);

    if (lastDigit > 5)
    {
        printf("greater than 5\n");
    }
    else if (lastDigit == 0)
    {
        printf("0\n");
    }
    else
    {
        printf("less than 6 and not 0\n");
    }

    return 0;
}
