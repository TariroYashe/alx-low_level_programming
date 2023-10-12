#include "lists.h"

/**
* print_dlistint - prints all the elements of a dlistint_t list
* @h: Pointer to the head of the doubly linked list
* Return: the number of nodes
*/
size_t print_dlistint(const dlistint_t *h)
{
size_t node_count = 0;  /*Initialize a variable to count nodes*/

while (h != NULL)
{
printf("%d\n", h->n);  /*Print the data of the current node*/
h = h->next;  /*Move to the next node*/
node_count++;  /*Increment the node count*/
}

return (node_count);  /*eturn the number of nodes*/
}
