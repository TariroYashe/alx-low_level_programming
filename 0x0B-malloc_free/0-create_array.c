#include "main.h"
#include <stdlib.h>

/**
* create_array - function that create an array of chars.
* @size: the array size
* @c: the initial value
* Description: creates an array of chars
* Return: a pointer to the array or NULL if it fails
*/

char *create_array(unsigned int size, char c)
{
char *array;
unsigned int i;

if (size == 0)
return (NULL);

array = (char *)malloc(sizeof(char) * size);
if (array == NULL)

return (NULL);


for (i = 0; i < size; i++)
array[i] = c;
{
return (array);
}
for (i = 0; i < size; i++)
array[i] = c;

return (array);
}
