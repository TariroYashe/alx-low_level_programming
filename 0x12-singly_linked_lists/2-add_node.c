#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* add_node -  func adds latest node at the beginning of link_t list
* @head: a double pointer to the list_t list
* @str:  the latest string to be added in the node
* Return: address of latest element, or if it fail return NULL
*/

list_t *add_node(list_t **head, const char *str)

{
list_t *latest;
unsigned int len = 0;

while (str[len])
len++;

latest = malloc(sizeof(list_t));
if (!latest)
return (NULL);

latest->str = strdup(str);
latest->len = len;
latest->next = (*head);
(*head) = latest;

return (*head);
}
