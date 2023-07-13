#include <stdlib.h>
#include "main.h"

/**
* *string_nconcat - concatenates n bytes of a string to another string
* @s1: string to append to
* @s2: string to concatenate from
* @n: number of bytes from s2 to concatenate to s1
* Return: pointer to string
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *s;
unsigned int x = 0, y = 0, length1 = 0, length2 = 0;

while (s1 && s1[length1])
length1++;
while (s2 && s2[length2])
length2++;

if (n < length2)
s = malloc(sizeof(char) * (length1 + n + 1));
else
s = malloc(sizeof(char) * (length1 + length2 + 1));

if (!s)
return (NULL);

while (x < length1)
{
s[x] = s1[x];
x++;
}

while (n < length2 && x < (length1 + n))
s[x++] = s2[y++];

while (n >= length2 && x < (length1 + length2))
s[x++] = s2[y++];

s[x] = '\0';

return (s);
}
