#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
* alloc_grid - returns a pointer to a 2D array of integers
* @width: width
* @height: height
* Description: returns a pointer to a 2D array of integers
* Return: 2D Array
*/

int **alloc_grid(int width, int height)
{
int **ptr;
int i, j;

if (width <= 0 || height <= 0)
{
return (NULL);
}

ptr = malloc(sizeof(int *) * height);

if (ptr == NULL)
{
return (NULL);
}

for (i = 0; i < height; i++)
{
ptr[i] = malloc(sizeof(int) * width);
if (ptr[i] == NULL)
{
for (j = 0; j < i; j++)
{
free(ptr[j]);
}
free(ptr);
return (NULL);
}
for (j = 0; j < width; j++)
{
ptr[i][j] = 0;
}
}
return (ptr);
}
