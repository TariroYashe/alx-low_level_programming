#include "lists.h"

/**
* listint_len - func that returns the number of elements in a listint_t
* @h: listint_t to be traversed
* Return: number of nodes
*/

size_t listint_len(const listint_t *h)
{
size_t num = 0;

while (h)
{
num++;
h = h->next;
}

return (num);
}

