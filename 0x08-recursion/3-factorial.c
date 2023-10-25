#include "main.h"

/**
 * factorial - Calculates the factorial of a number.
 * @n: The input number.
 * 
 * Return: The factorial of n. If n is lower than 0, returns -1.
 */
int factorial(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0) 
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1); 
    }
}
