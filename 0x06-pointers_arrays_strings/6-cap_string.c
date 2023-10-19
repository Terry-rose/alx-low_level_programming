#include "main.h"
#include <stdbool.h>

/**
 * is_separator - Checks if a character is a word separator
 * @c: Character to check
 *
 * Return: true if character is a separator, false otherwise
 */
bool is_separator(char c)
{
    char separators[] = " \t\n,;.!?\"(){}";
    int i;

    for (i = 0; separators[i] != '\0'; i++) {
        if (c == separators[i]) {
            return true;
        }
    }

    return false;
}

/**
 * cap_string - Capitalizes all words of a string
 * @str: Input string
 *
 * Return: Pointer to the modified string
 */
char *cap_string(char *str)
{
    char *ptr = str;
    bool new_word = true;

    while (*ptr != '\0') {
        if (new_word && (*ptr >= 'a' && *ptr <= 'z')) {
            *ptr = *ptr - 'a' + 'A';
            new_word = false;
        } else if (is_separator(*ptr)) {
            new_word = true;
        } else {
            new_word = false;
        }
        ptr++;
    }

    return str;
}
