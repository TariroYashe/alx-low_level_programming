#include "lists.h"

/**
* pop_listint - function that deletes the head node of a linked list
* @head: pointer address to the first element in the linked list
* Return: returns the head node’s data,
* or 0 if the list is empty
*/
int pop_listint(listint_t **head)
{
listint_t *temp = NULL;
int num = 0;

if (head && *head)
{
num = (*head)->n;
temp = (*head)->next;
free(*head);
*head = temp;
}

return (temp ? num : 0);
}

