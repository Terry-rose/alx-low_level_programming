#include <stdio.h>
#include <stdlib.h>

void multiply(char num1[], char num2[]) {
    int len1 = 0, len2 = 0, i, j, k, carry = 0;
    int *result;
    
    while (num1[len1] != '\0') len1++;
    while (num2[len2] != '\0') len2++;
    
    result = malloc(sizeof(int) * (len1 + len2));
    
    for (i = 0; i < len1 + len2; i++) {
        result[i] = 0;
    }
    
    for (i = len1 - 1; i >= 0; i--) {
        carry = 0;
        for (j = len2 - 1, k = i + len2; j >= 0; j--, k--) {
            int temp = (num1[i] - '0') * (num2[j] - '0') + result[k] + carry;
            result[k] = temp % 10;
            carry = temp / 10;
        }
        result[k] += carry;
    }
    
    for (i = 0; i < len1 + len2; i++) {
        if (result[i] != 0) {
            break;
        }
    }
    
    for (; i < len1 + len2; i++) {
        printf("%d", result[i]);
    }
    printf("\n");
    
    free(result);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 98;
    }
    
    char *num1 = argv[1];
    char *num2 = argv[2];
    
    for (int i = 0; num1[i] != '\0'; i++) {
        if (num1[i] < '0' || num1[i] > '9') {
            printf("Error\n");
            return 98;
        }
    }
    
    for (int i = 0; num2[i] != '\0'; i++) {
        if (num2[i] < '0' || num2[i] > '9') {
            printf("Error\n");
            return 98;
        }
    }
    
    multiply(num1, num2);
    
    return 0;
}

