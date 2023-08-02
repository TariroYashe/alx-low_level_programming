#include "lists.h"

/**
* sum_listint_recursive - Helper function for calculating the sum recursively.
* @node: current node in the linked list
*
* Return: sum of the data in the linked list
*/
int sum_listint_recursive(listint_t *node)
{
if (node == NULL)
return (0);

return (node->n + sum_listint_recursive(node->next));
}

/**
* sum_listint - Calculates the sum of all the data in a..
* listint_t list recursively.
* @head: first node in the linked list
*
* Return: resulting sum
*/
int sum_listint(listint_t *head)
{
return (sum_listint_recursive(head));
}

