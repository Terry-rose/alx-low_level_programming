#include <stdio.h>

int main(void)
{
    char letter = 'z'; /*Start with 'z', the last lowercase letter*/

    while (letter >= 'a') {
        putchar(letter);
        letter--;
    }

    putchar('\n'); /*Print a new line*/

    return 0;
}

