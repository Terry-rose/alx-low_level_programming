#include "lists.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * free_list - frees a list_t list.
 * @head: pointer to the head of the linked list
 */
void free_list(list_t *head)

{
list_t *current, *next;

current = head;

while (current != NULL)
{
next = current->next;
free(current->str);
free(current);
current = next;
}
}
