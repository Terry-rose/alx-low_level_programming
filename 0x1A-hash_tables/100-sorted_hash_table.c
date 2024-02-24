#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node, *current_node;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    current_node = ht->shead;

    while (current_node != NULL && strcmp(key, current_node->key) > 0)
        current_node = current_node->snext;

    if (current_node != NULL && strcmp(key, current_node->key) == 0)
    {
        free(current_node->value);
        current_node->value = strdup(value);
        if (current_node->value == NULL)
            return (0);
        return (1);
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    if (current_node == NULL)
    {
        new_node->sprev = ht->stail;
        new_node->snext = NULL;
        if (ht->stail != NULL)
            ht->stail->snext = new_node;
        else
            ht->shead = new_node;
        ht->stail = new_node;
    }
    else
    {
        new_node->sprev = current_node->sprev;
        new_node->snext = current_node;
        if (current_node->sprev != NULL)
            current_node->sprev->snext = new_node;
        else
            ht->shead = new_node;
        current_node->sprev = new_node;
    }

    return (1);
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
    shash_node_t *current_node;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    current_node = ht->shead;

    while (current_node != NULL && strcmp(key, current_node->key) > 0)
        current_node = current_node->snext;

    if (current_node != NULL && strcmp(key, current_node->key) == 0)
        return (current_node->value);

    return (NULL);
}

void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *current_node;

    if (ht == NULL)
        return;

    printf("{");

    current_node = ht->shead;

    while (current_node != NULL)
    {
        printf("'%s': '%s'", current_node->key, current_node->value);
        if (current_node->snext != NULL)
            printf(", ");
        current_node = current_node->snext;
    }

    printf("}\n");
}

void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *current_node;

    if (ht == NULL)
        return;

    printf("{");

    current_node = ht->stail;

    while (current_node != NULL)
    {
        printf("'%s': '%s'", current_node->key, current_node->value);
        if (current_node->sprev != NULL)
            printf(", ");
        current_node = current_node->sprev;
    }

    printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *current_node, *next_node;

    if (ht == NULL)
        return;

    current_node = ht->shead;

    while (current_node != NULL)
    {
        next_node = current_node->snext;
        free(current_node->key);
        free(current_node->value);
        free(current_node);
        current_node = next_node;
    }

    free(ht->array);
    free(ht);
}

