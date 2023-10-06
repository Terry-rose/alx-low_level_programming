#include <stdio.h>

int main(void)
{
    int digit = 0;

    while (digit <= 9)
    {
        putchar(digit + '0'); /*Convert digit to character and print*/
        digit++;
    }

    putchar('\n');  /*Print a new line after printing the numbers*/

    return 0;
}

