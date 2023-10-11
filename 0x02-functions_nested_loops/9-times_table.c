#include "main.h"
#include <stdio.h>

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int i, j, result;

	for (i = 0; i <= 9; i++)
{
	for (j = 0; j <= 9; j++)
{
	result = i * j;

	if (j == 0)
{
	printf("%d", result);
}
else
{
	printf(", %d", result / 10 == 0 ? result : result % 10);
}
}


printf("\n");
}
}
