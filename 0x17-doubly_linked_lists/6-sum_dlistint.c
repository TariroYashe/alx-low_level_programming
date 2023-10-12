#include "lists.h"

/**
* sum_dlistint - Computes the sum of all the data in a dlistint_t linked list.
* @head: A pointer to the head of the linked list.
*
* Return: The sum of all the data values. If the list is empty, return 0.
*/
int sum_dlistint(dlistint_t *head)
{
int sum = 0;

while (head != NULL)
{
sum += head->n;
head = head->next;
}

return (sum);
}
