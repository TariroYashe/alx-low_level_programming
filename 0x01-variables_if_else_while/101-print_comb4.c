#include <stdio.h>

/**
 * main - entry point
 *
 * Description: print all possible different combinations of three digits
 *
 * Return: always 0
 */

int main void

{
int x, y, z;

for (x = 48; x < 58; x++)
{
for (y = 49; y < 58; y++)
{
for (z = 50; x < 58; z++)
{
if (z > y && y > x)
{
putchar(x);
putchar(y);
putchar(z);
if (x != 55 || y != 56)
{
putchar(',');
putchar(' ');
}
}
}
}
}
putchar('\n');
return (0);
}
