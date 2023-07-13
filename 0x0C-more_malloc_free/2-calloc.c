#include "main.h"
#include <stdlib.h>
/**
* _calloc - function to allocates memory for an array.
* @nmemb: number of elements.
* @size: size of bytes.
* Return: pointer to the allocated memory.
* if nmemb or size is 0 then calloc returns NULL.
* if malloc fails then calloc returns NULL.
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
char *pnter;
unsigned int n;

if (nmemb == 0 || size == 0)
return (NULL);

pnter = malloc(nmemb * size);

if (pnter == NULL)
return (NULL);

for (n = 0; n < (nmemb * size); n++)
pnter[n] = 0;

return (pnter);
}

