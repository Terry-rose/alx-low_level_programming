#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1, otherwise -1.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * print_most_numbers - prints the numbers from 0 to 9, excluding 2 and 4,
 * followed by a new line
 */
void print_most_numbers(void)
{
    char digit;

    for (digit = '0'; digit <= '9'; digit++)
    {
        if (digit != '2' && digit != '4')
        {
            _putchar(digit);
        }
    }

    _putchar('\n');
}
