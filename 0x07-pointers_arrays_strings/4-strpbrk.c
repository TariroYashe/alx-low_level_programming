#include "main.h"

/**
*_strpbrk - function that search a string for any of a set of bytes.
*@s: a string to be searched.
*@accept: a set of bytes to be searched.
*Return: a pointer if a set is matched. Nul ifnot matched.
*/

char *_strpbrk(char *s, char *accept)
{
int zayn;
while (*s)
{
for (zayn = 0; accept[zayn]; zayn++)
{
if (*s == accept[zayn])
return (s);
}
s++;
}
return ('\0');
}
