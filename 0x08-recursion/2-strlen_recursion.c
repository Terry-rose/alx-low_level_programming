#include "main.h"

/**
 * _strlen_recursion - Calculates the length of a string recursively.
 * @s: The input string.
 * 
 * Return: The length of the string.
 */
int _strlen_recursion(char *s)
{
    if (*s == '\0') /* Base case: if the current character is null terminator */
    {
        return 0; /* Length of the string is 0*/
    }
    
    return 1 + _strlen_recursion(s + 1); /* Recursive call with the next character in the string */
}
