#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The input string.
 * @accept: The characters to match in the initial segment of s.
 *
 * Return: The number of bytes in the initial segment of s which consist
 * only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept) {
    unsigned int count = 0;
    int match;

    while (*s != '\0') {
        match = 0;
        char *temp_accept = accept; /* Use a temporary pointer to iterate through accept */

        while (*temp_accept != '\0') {
            if (*s == *temp_accept) {
                match = 1;
                break;
            }
            temp_accept++;
        }

        if (match) {
            count++;
        } else {
            break;
        }

        s++;
    }

    return count;
}
