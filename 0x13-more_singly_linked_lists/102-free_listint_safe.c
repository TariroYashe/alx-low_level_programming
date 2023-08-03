#include "lists.h"

/**
* free_listint_safe - frees a linked list
* @h: pointer to the first node in the linked list
*
* Return: number of elements in the freed list
*/
size_t free_listint_safe(listint_t **h)
{
size_t len
listint_t *current
if (!h || !*h)
return (0);

*current = *h;
*h = (*h)->next;

len = free_listint_safe(h);
free(current);
return (len + 1);
}

