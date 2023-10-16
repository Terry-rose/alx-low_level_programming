#include "main.h"

/**
 * rev_string - reverses a string
 * @s: input string
 */
void rev_string(char *s)
{
    int length = 0;
    int start = 0;
    int end;

    /* Calculate the length of the string */
    while (s[length] != '\0')
    {
        length++;
    }

    /* Set the end index to the last character (before null terminator) */
    end = length - 1;

    /* Reverse the string by swapping characters from start to end */
    while (start < end)
    {
        /* Swap characters at start and end indices */
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        /* Move start index forward and end index backward */
        start++;
        end--;
    }
}
