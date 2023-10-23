#include "main.h"
#include <stddef.h>

/**
 * _strstr - Locates a substring within another string.
 * @haystack: The main string to search.
 * @needle: The substring to locate in the haystack.
 *
 * Return: A pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle) {
    while (*haystack != '\0') {
        char *temp_haystack = haystack;
        char *temp_needle = needle;

        while (*temp_haystack != '\0' && *temp_needle != '\0' && *temp_haystack == *temp_needle) {
            temp_haystack++;
            temp_needle++;
        }

        /* If the entire needle is found in the haystack, return the pointer to the start of the match */
        if (*temp_needle == '\0') {
            return haystack;
        }

        haystack++; /* Move to the next character in the haystack */
    }

    return NULL; /* Return NULL if the substring is not found */
}
