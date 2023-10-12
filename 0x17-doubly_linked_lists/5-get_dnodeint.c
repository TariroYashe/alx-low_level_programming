#include "lists.h"

/**
* get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
* @head: A pointer to the head of the doubly linked list.
* @index: The index of the node, starting from 0.
*
* Return: If the node does not exist, return NULL. Otherwise, return the node.
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
dlistint_t *current = head;
unsigned int i = 0;

while (current != NULL && i < index)
{
current = current->next;
i++;
}

if (current == NULL)
{
return (NULL);  /*Node at the specified index does not exist*/
}
return (current);  /*Node found at the specified index*/
}
