#include "main.h"

/**
* _strncpy - a function that copies a string.
* @dest: destination
* @src: source
* @n: number of bytes used.
* Description: "a function that copies a string."
* Return: copied string
*/

char *_strncpy(char *dest, char *src, int n)
{
int size_in_bytes;

for (size_in_bytes = 0; size_in_bytes < n && src[size_in_bytes] != '\0'; size_in_bytes++)
dest[size_in_bytes] = src[size_in_bytes];

for (size_in_bytes = 0; size_in_bytes < n; size_in_bytes++)
dest[size_in_bytes] = '\0';

return (dest);
}
