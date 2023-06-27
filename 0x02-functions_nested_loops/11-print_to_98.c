#include "main.h"
#include <stdio.h>

/**
* print_to_98 - prints values to 98
* @n: int arg
*
* Descrption: "prints values from n - 98"
*
* Return: list of integers
*
*/

void print_to_98(int n)
{
int start;

if (n > 98)
{
for (start = n; start >= 98; start--)
{
printf("%d", start);
if (start == 98)
{
break;
}
else
{
printf(", ");
}
}
}
else
{
for (start = n; start <= 98; start++)
{
printf("%d", start);
if (start == 98)
{
break;
}
else
{
printf(", ");
}
}
}
printf("\n");
}
