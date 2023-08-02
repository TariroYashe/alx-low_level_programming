#include "lists.h"

/**
* add_nodeint - func that adds a new node to a linked list
* @head: The pointer to first node in the list
* @n: data to be put new node
* Return: the address of the new element, or NULL if it failed
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new = malloc(sizeof(listint_t));
if (new)
{
new->n = n;
new->next = *head;
*head = new;
}
return (new ? new : NULL);
}

