#include "main.h"

/**
*_strstr - function that locate a substring.
*@haystack: a string to besearched.
*@needle: a substring to be located.
*Return: beginning pointer of located substring if located. Nul if not
*/

char *_strstr(char *haystack, char *needle)

{
int nish;
if (*needle == 0)
return (haystack);

while (*haystack)
{
nish = 0;
if (haystack[nish] == needle[nish])
{

do
{
if (needle[nish + 1] == '\0')
return (haystack);
nish++;
}

while (haystack[nish] == needle[nish]);
}
haystack++;
}
return ('\0');
}
