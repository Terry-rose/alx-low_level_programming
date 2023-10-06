#include <stdio.h>

int main(void)
{
    char lowercase = 'a';
    char uppercase = 'A';

    /*Print lowercase alphabet*/
    while (lowercase <= 'z')
    {
        putchar(lowercase);
        lowercase++;
    }

    /*Print uppercase alphabet*/
    while (uppercase <= 'Z')
    {
        putchar(uppercase);
        uppercase++;
    }

    /*Print a new line*/
    putchar('\n');

    return 0;
}

