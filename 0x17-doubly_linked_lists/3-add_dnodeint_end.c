#include "lists.h"

/**
* add_dnodeint_end - Add a new node at the end of a doubly linked list.
* @head: A pointer to the head of the list.
* @n: The integer value to be added to the new node.
*
* Return: The address of the new element, or NULL if it fails.
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *new_node;
dlistint_t *current;

/* Allocate memory for the new node */
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

/* Assign the value n to the new node */
new_node->n = n;
new_node->next = NULL;

/* If the list is empty, set new node's prev to NULL and update the head */
if (*head == NULL)
{
new_node->prev = NULL;
*head = new_node;
return (new_node);
}

current = *head;

/* Traverse the list to find the last node */
while (current->next != NULL)
{
current = current->next;
}

/* Update the last node's next and new node's prev */
current->next = new_node;
new_node->prev = current;

return (new_node);
}
