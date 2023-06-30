#include "main.h"

/**
*ro13 - encoder rot13
* @s: pointer to the string parameter.
* Return: a string
*/

char *rot13(char *s)
{
int x;
int y;
char data1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char data2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

for (x = 0; s[x] != '\0'; x++)
{
for (y = 0; y < 52; y++)
{
if (s[x] == data1[y])
{
s[x] = data2[y];
break;
}
}
}
return (s);
}

