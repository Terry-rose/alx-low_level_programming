#include <stdio.h>

void puts_half(char *str)
{
    int length = 0;
    int i, start;

    /* Calculate the length of the string */
    while (str[length] != '\0') {
        length++;
    }

    /* Calculate the starting index based on odd or even length */
    if (length % 2 == 0) {
        start = length / 2;
    } else {
        start = (length - 1) / 2;
    }

    /* Print the second half of the string */
    for (i = start; i < length; i++) {
        putchar(str[i]);
    }
    putchar('\n');
}
