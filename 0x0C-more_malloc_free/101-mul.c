#include <stdio.h>
#include <stdlib.h>

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int multiply(char *num1, char *num2) {
    int len1 = 0, len2 = 0;
    int *result, i, j, carry = 0;

    while (num1[len1] != '\0') {
        if (!is_digit(num1[len1])) {
            printf("Error\n");
            exit(98);
        }
        len1++;
    }

    while (num2[len2] != '\0') {
        if (!is_digit(num2[len2])) {
            printf("Error\n");
            exit(98);
        }
        len2++;
    }

    result = malloc(sizeof(int) * (len1 + len2));
    if (result == NULL) {
        printf("Error\n");
        exit(98);
    }

    for (i = 0; i < len1 + len2; i++) {
        result[i] = 0;
    }

    for (i = len1 - 1; i >= 0; i--) {
        int digit1 = num1[i] - '0';
        carry = 0;
        for (j = len2 - 1; j >= 0; j--) {
            int digit2 = num2[j] - '0';
            int temp = result[i + j + 1] + (digit1 * digit2) + carry;
            result[i + j + 1] = temp % 10;
            carry = temp / 10;
        }
        result[i + j + 1] += carry;
    }

    for (i = 0; i < len1 + len2; i++) {
        if (!(i == 0 && result[i] == 0)) {
            printf("%d", result[i]);
        }
    }
    printf("\n");

    free(result);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 98;
    }

    multiply(argv[1], argv[2]);

    return 0;
}

