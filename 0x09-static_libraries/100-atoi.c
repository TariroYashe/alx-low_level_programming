#include "main.h"

/**
* _atoi - convert a string to an integer
* @z: the ponter to convert
* Return: an integer
*/

int _atoi(char *z)
{
int c = 0;
unsigned int a = 0;
int min = 1;
int isi = 0;

while (z[c])

{
if (z[c] == 45)
{
min *= -1;
}

while (z[c] >= 48 && z[c] <= 57)
{
isi = 1;
a = (a * 10) + (z[c] - '0');
c++;
}
if (isi == 1)
{
break;
}
c++;
}
a *= min;
return (a);
}
