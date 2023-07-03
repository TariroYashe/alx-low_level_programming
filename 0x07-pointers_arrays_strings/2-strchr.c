

#include "main.h"
/**
*_strchr - function to locate a character in a string.
*@s: a string to be searched
*@c: a character to be located by strchr
*Return: if c is found - a pointer to the first occurance, if not found - null
*/

char *_strchr(char *s, char c)

{
int yashe;

for (yashe = 0; s[yashe] >= '\n'; yashe++)
{
if (s[yashe] == c)
return (s + yashe);
}
return ('\0');
}

