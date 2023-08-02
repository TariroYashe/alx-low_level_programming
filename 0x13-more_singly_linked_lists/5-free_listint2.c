#include "lists.h"

/**
* free_listint2 - func frees a linked list
* @head: pointer address to the linked list to be freed
*/
void free_listint2(listint_t **head)
{
listint_t *current;
listint_t *next_node;

if (head == NULL || *head == NULL)
return;

current = *head;

while (current)
{
next_node = current->next;
free(current);
current = next_node;
}

*head = NULL;
}

