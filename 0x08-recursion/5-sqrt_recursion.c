#include "main.h"

int find_sqrt(int n, int start, int end);

/**
 * _sqrt_recursion - Calculates the natural square root of a number recursively.
 * @n: The input number.
 *
 * Return: The natural square root of n. If n does not have a natural square root, returns -1.
 */
int _sqrt_recursion(int n)
{
    if (n < 0) 
    {
        return -1;
    }

    return find_sqrt(n, 1, n);
}

/**
 * find_sqrt - Helper function to find the square root using recursion.
 * @n: The input number.
 * @start: The start of the search range.
 * @end: The end of the search range.
 *
 * Return: The square root of n if found, otherwise, -1.
 */
int find_sqrt(int n, int start, int end)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2; 

        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            return find_sqrt(n, start, mid - 1);
        }
        else
        {
            return find_sqrt(n, mid + 1, end);
        }
    }

    return -1; 
}
