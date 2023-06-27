#include "main.h"
#include <stdio.h>
/**
* times_table - prints multiplication table
*
* Description: "prints multiplication table"
*
* Return: retuns a table of multiples
*
*/

void times_table(void)
{
int j, k, l, m, n;

for (j = 0; j <= 9; j++)
{
for (k = 0; k <= 9; k++)
{
l = j * k;
if (l > 9)
{
m = l % 10;
n = (l - m) / 10;
_putchar(44);
_putchar(32);
_putchar(n + '0');
_putchar(m + '0');
}
else
{
if (k != 0)
{
_putchar(44);
_putchar(32);
_putchar(32);
}
_putchar(l + '0');
}
}
_putchar('\n');
}
}
