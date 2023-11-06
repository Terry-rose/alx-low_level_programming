#include "dog.h"
#include <stddef.h>

/**
 * init_dog - initializes a struct dog
 * @d: pointer to the struct dog
 * @name: pointer to the name string
 * @age: age of the dog
 * @owner: pointer to the owner string
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d != NULL)
    {
        d->name = name;
        d->age = age;
        d->owner = owner;
    }
}
