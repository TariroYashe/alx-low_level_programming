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
int filesize;

for (filesize = 0; filesize < n && src[filesize] != '\0'; filesize++)
dest[filesize] = src[filesize];

for (; filesize < n; filesize++)
dest[filesize] = '\0';

return (dest);
}

