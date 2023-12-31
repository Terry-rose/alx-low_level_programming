#include <stdlib.h>

char *create_array(unsigned int size, char c) {
    char *array;
    unsigned int i;

    array = malloc(sizeof(char) * size);

    if (array == NULL) {
        return NULL;
    }

    for (i = 0; i < size; ++i) {
        array[i] = c;
    }

    return array;
}
