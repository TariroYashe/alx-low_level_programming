#include "lists.h"

/**
* insert_dnodeint_at_index - Inserts a new node at a given position.
* @h: A pointer to the address of the head node.
* @idx: The index where the new node should be added.
* @n: The value to store in the new node.
* Return: The address of the new node, or NULL if it failed.
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *current = *h;
unsigned int i = 0;

if (!h)
return (NULL);

new_node = malloc(sizeof(dlistint_t));
if (!new_node)
return (NULL);

new_node->n = n;

if (idx == 0)
{
/* Insert at the beginning of the list */
new_node->next = *h;
new_node->prev = NULL;
if (*h)
(*h)->prev = new_node;
*h = new_node;
return (new_node);
}

while (current)
{
if (i == idx)
{
/* Insert at the specified index */
new_node->next = current;
new_node->prev = current->prev;
current->prev = new_node;
if (new_node->prev)
new_node->prev->next = new_node;
return (new_node);
}
current = current->next;
i++;
}

if (i == idx)
{
/* Insert at the end of the list */
new_node->next = NULL;
new_node->prev = current;
if (current)
current->next = new_node;
return (new_node);
}

free(new_node);  /*If index is out of bounds*/
return (NULL);
}
