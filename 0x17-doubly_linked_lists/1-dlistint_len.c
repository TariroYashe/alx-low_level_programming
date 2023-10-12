#include "lists.h"

/**
* dlistint_len - Returns the number of elements in a dlistint_t list.
* @h: Pointer to the head of the list.
*
* Return: The number of elements in the list.
*/
size_t dlistint_len(const dlistint_t *h)
{
size_t count = 0; /* Initialize the count to zero*/

/*Traverse the list and count the elements*/
while (h != NULL)
{
count++;
h = h->next;
}

return (count);
}
