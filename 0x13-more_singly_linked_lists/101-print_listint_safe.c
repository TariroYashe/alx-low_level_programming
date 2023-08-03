#include "lists.h"
#include <stdio.h>

/**
* looped_listint_len - Counts the number of unique nodes
* in a looped listint_t linked list.
* @head: A pointer adrr to the head of the list to check.
*
* Return: If the list is not looped - 0.
* else - the nodes in the list.
*/
size_t looped_listint_len(const listint_t *head)
{
const listint_t *dog = head, *cat = head;

while (dog && cat && cat->next)
{
dog = dog->next;
cat = cat->next->next;

if (dog == cat)
{
size_t nodes = 1;
cat = cat->next;

while (dog != cat)
nodes++, cat = cat->next;

return (nodes);
}
}

return (0);
}

