#include "main.h"

/**
 * _strncat - Concatenates two strings up to n bytes from src
 * @dest: Destination string
 * @src: Source string
 * @n: Number of bytes from src to be concatenated
 *
 * Return: Pointer to the resulting string `dest`
 */
char *_strncat(char *dest, char *src, int n)
{
    char *ptr = dest;

    while (*ptr != '\0') {
        ptr++;
    }

    while (*src != '\0' && n > 0) {
        *ptr = *src;
        ptr++;
        src++;
        n--;
    }

    *ptr = '\0';

    return dest;
}
