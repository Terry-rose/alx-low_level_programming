#include <stdio.h>

int main(void)
{
    char hexDigit;
    int i;

    for (i = 0; i < 16; i++) {
        if (i < 10) {
            hexDigit = i + '0';  /*Convert digit to character*/
        } else {
            hexDigit = i - 10 + 'a';  /*Convert 10-15 to 'a' to 'f'*/
        }
        putchar(hexDigit);  /*Print the hexadecimal digit*/
    }

    putchar('\n');  /*Print a new line*/

    return 0;
}
