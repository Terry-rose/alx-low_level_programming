#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees memory allocated for a dog structure
 * @d: pointer to the dog structure
 *
 * Return: void
 */
void free_dog(dog_t *d)
{
    if (d != NULL)
    {
        /* Free the dynamically allocated name and owner strings */
        free(d->name);
        free(d->owner);
        /* Free the dog structure itself */
        free(d);
    }
}
