#include "main.h"
/**
* _strspn - obtain/gets the length of prefix substring.
*@s: a string to be searched
*@accept: a prefix to be measured
*Return: number of bytes in s comprising only bytes from 'accept'.
*/

unsigned int _strspn(char *s, char *accept)

{
unsigned int bytes = 0;
int tariro;
while (*s)
{
for (tariro = 0; accept[tariro]; tariro++)
{
if (*s == accept[tariro])
{
bytes++;
break;
}
else if (accept[tariro + 1] == '\0')
return (bytes);
}
s++;
}
return (bytes);
}
