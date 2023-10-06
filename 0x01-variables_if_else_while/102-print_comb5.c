#include <stdio.h>


int main() {
    int tens_digit_1, units_digit_1, tens_digit_2, units_digit_2;

    for (tens_digit_1 = 0; tens_digit_1 <= 9; ++tens_digit_1) {
        for (units_digit_1 = 0; units_digit_1 <= 9; ++units_digit_1) {
            for (tens_digit_2 = 0; tens_digit_2 <= 9; ++tens_digit_2) {
                for (units_digit_2 = 0; units_digit_2 <= 9; ++units_digit_2) {
                    /*Check if the combination is in ascending order*/
                    if (tens_digit_1 <= tens_digit_2 && units_digit_1 <= units_digit_2) {
                        /*Print tens digit and units digit of first number*/
                        putchar(tens_digit_1 + '0');
                        putchar(units_digit_1 + '0');
                        putchar(' ');

                        /*Print tens digit and units digit of second number*/
                        putchar(tens_digit_2 + '0');
                        putchar(units_digit_2 + '0');

                        /*Print separator and space if it's not the last combination*/
                        if (tens_digit_1 != 9 || units_digit_1 != 9 || tens_digit_2 != 9 || units_digit_2 != 9) {
                            putchar(',');
                            putchar(' ');
                        }
                    }
                }
            }
        }
    }

    putchar('\n'); /*Print a newline character at the end*/

    return 0;
}

