#include <stdlib.h>
#include <string.h>
#include "main.h"

void *_calloc(unsigned int nmemb, unsigned int size)
{
    void *ptr;
    unsigned int total_size = nmemb * size;

    if (nmemb == 0 || size == 0)
        return NULL;

    ptr = malloc(total_size);

    if (ptr == NULL)
        return NULL;

    memset(ptr, 0, total_size);

    return ptr;
}
