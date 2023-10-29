#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int i, num, sum = 0;

    if (argc < 2) {
        printf("0\n");
        return 0;
    }

    for (i = 1; i < argc; i++) {
        int j = 0;
        while (argv[i][j] != '\0') {
            if (!isdigit(argv[i][j])) {
                printf("Error\n");
                return 1;
            }
            j++;
        }
        num = atoi(argv[i]);
        sum += num;
    }

    printf("%d\n", sum);
    return 0;
}
