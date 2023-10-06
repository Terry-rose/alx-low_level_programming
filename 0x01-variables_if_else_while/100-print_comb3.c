#include <stdio.h>


int main() {
    int i, j;

    for (i = 0; i < 9; ++i) {
        for (j = i + 1; j <= 9; ++j) {
            /*Print two digits separated by ", "*/
            putchar(i + '0');
            putchar(j + '0');

            /*If it's not the last combination, print separator and space*/
            if (i != 8 || j != 9) {
                putchar(',');
                putchar(' ');
            }
        }
    }

    putchar('\n'); /*Print a newline character at the end*/

    return 0;
}
