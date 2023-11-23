#include "main.h"

/**
 * print_binary-Prints the binary representation of a number.
 * @n:The number to be converted and printed.
 */
void print_binary(unsigned long int n)

{

int shift;

if (n == 0)

{

_putchar('0');
return;

}

for (shift = sizeof(unsigned long int) * 8 - 1; shift >= 0; shift--)

{

if ((n >> shift) & 1)
break;

}

for (; shift >= 0; shift--)
_putchar((n >> shift) & 1 ? '1' : '0');
}

