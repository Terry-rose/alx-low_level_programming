#include <stdio.h>

int main(void)
{
    char letter = 'a';

    while (letter <= 'z')
    {
        /*Check if the current letter is 'q' or 'e'; if not, print it*/
        if (letter != 'q' && letter != 'e')
        {
            putchar(letter);
        }
        letter++;
    }

    putchar('\n');  /*Print a new line after printing the letters*/

    return 0;
}

