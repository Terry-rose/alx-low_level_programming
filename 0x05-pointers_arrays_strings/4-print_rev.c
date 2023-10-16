#include "main.h"
#include <stdio.h>

/**
 * print_rev - prints a string in reverse followed by a new line
 * @s: input string
 */
void print_rev(char *s)
{
    int length = 0;
    int i;

    /* Calculate the length of the input string */
    while (s[length] != '\0')
    {
        length++;
    }

    /* Print the string in reverse order */
    for (i = length - 1; i >= 0; i--)
    {
        putchar(s[i]);
    }

    /* Print a new line after the reversed string */
    putchar('\n');
}
