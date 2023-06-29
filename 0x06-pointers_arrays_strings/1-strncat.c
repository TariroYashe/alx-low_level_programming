#include "main.h"

/**
 * _strncat - a func that concats two stings
 * @dest: destination
 * @src: src string
 * @n: bytes in src
 * Description: "A function that concats two strings"
 * Return: a string
 */

char *_strncat(char *dest, char *src, int n)
{
int string_length, x;
string_length = 0;
while (dest[string_length] != '\0')
{
string_length++;
}
for (x = 0; x < n && src[x] != '\0'; x++, string_length++)
{
dest[string_length] = src[x];
}
dest[string_length] = '\0';
return (dest);
}
