#include "main.h"

/**
* _strcat -  function appends the src string to the dest string.
* @dest: is the destination string pointer.
* @src: is the source string pointer.
* Return: pointer to destination string.
*/

char *_strcat(char *dest, char *src)
{
int string_length, x;

string_length = 0;
while (dest[string_length] != '\0')
{
string_length++;
}

for (x = 0; src[x] != '\0'; x++, string_length++)
{
dest[string_length] = src[x];
}
dest[string_length] = '\0';
return (dest);
}

