#include <stdlib.h>
#include "main.h"

/**
* *array_range - function that creates an array of integers
* @min: minimum range of stored values
* @max: maximum range of stored values & number of elements
*
* Return: pointer to the new array
* If min > max, return NULL
* If malloc fails, return NULL
*/

int *array_range(int min, int max)
{
int *pnter;
int i, size;

if (min > max)
return (NULL);

size = max - min + 1;

pnter = malloc(sizeof(int) * size);

if (pnter == NULL)
return (NULL);

for (i = 0; min <= max; i++)
pnter[i] = min++;

return (pnter);
}

