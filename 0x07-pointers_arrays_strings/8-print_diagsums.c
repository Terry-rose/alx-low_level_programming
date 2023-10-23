#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix.
 * @a: The square matrix of integers.
 * @size: The size of the matrix.
 */
void print_diagsums(int *a, int size) {
    int i, primary_diag_sum = 0, secondary_diag_sum = 0;

    for (i = 0; i < size; i++) {
        primary_diag_sum += *(a + i * size + i); /* Sum of elements on the primary diagonal */
        secondary_diag_sum += *(a + i * size + (size - 1 - i)); /* Sum of elements on the secondary diagonal */
    }

    printf("%d, %d\n", primary_diag_sum, secondary_diag_sum);
}
