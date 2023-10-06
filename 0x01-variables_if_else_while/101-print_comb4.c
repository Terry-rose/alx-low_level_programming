#include <stdio.h>


int main() {
    int i, j, k;

    for (i = 0; i <= 7; ++i) {
        for (j = i + 1; j <= 8; ++j) {
            for (k = j + 1; k <= 9; ++k) {
                /*Print three digits separated by ", "*/
                putchar(i + '0');
                putchar(j + '0');
                putchar(k + '0');

                /*If it's not the last combination, print separator and space*/
                if (i != 7 || j != 8 || k != 9) {
                    putchar(',');
                    putchar(' ');
                }
            }
        }
    }

    putchar('\n'); /*Print a newline character at the end*/

    return 0;
}

