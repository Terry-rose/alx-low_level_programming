#include <stdlib.h>
#include "main.h"

/**
 * str_concat - Concatenates two strings.
 * @s1: The first input string.
 * @s2: The second input string.
 *
 * Return: A pointer to a newly allocated space in memory
 *         containing the concatenated string, or NULL on failure.
 */
char *str_concat(char *s1, char *s2) {
    unsigned int len1 = 0, len2 = 0, i, j;
    char *concatenated;

    if (s1 == NULL) {
        s1 = "";
    }
    if (s2 == NULL) {
        s2 = "";
    }	

    /* Calculate the length of s1 */
    while (s1[len1] != '\0') {
        len1++;
    }

    /* Calculate the length of s2 */
    while (s2[len2] != '\0') {
        len2++;
    }

    /* Allocate memory for the concatenated string (+1 for null terminator) */
    concatenated = malloc(sizeof(char) * (len1 + len2 + 1));

    if (concatenated == NULL) {
        return NULL;
    }

    /* Copy characters from s1 to concatenated */
    for (i = 0; i < len1; i++) {
        concatenated[i] = s1[i];
    }

    /* Copy characters from s2 to concatenated */
    for (j = 0; j < len2; j++) {
        concatenated[i + j] = s2[j];
    }

    concatenated[i + j] = '\0'; 
    return concatenated;
}
