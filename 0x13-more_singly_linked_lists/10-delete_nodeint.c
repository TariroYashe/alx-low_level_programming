#include "lists.h"

/**
* delete_nodeint_at_index - deletes a node in a linked list at a certain index
* @head: pointer to the first element in the list
* @index: index of the node to delete
*
* Return: 1 (Success), or -1 (Fail)
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{

unsigned int i;
listint_t **prev_next = head;
listint_t *current = *head;

if (head == NULL || *head == NULL)
return (-1);

for (i = 0; current != NULL && i < index; i++)
{
prev_next = &current->next;
current = current->next;
}

return (current == NULL ? -1 : (*prev_next = current->next, free(current), 1));
}

