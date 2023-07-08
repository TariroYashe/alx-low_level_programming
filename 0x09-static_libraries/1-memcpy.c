#include "main.h"
/**
*_memcpy- a function tat copies @n bytes from memory area @src to memory @dest
*@src: bytes from memory area
*@n: copied function
*@dest: to memory area
*Return: a pointer to @dest (to memory area)
*/

char *_memcpy(char *dest, char *src, unsigned int n)

{
unsigned int j = 0;
while (j < n)
{
dest[j] = src[j];
j++;
}

return (dest);
}
