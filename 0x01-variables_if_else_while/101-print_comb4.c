#include <stdio.h>

/**
 * main - entry point
 *
 * Description: print all possible different combinations of three digits
 *
 * Return: always 0
 */

int main(void)

{
int x, y, z;

for (x = 0; x < 7; x++)
{
for (y = x + 1; y < 8; y++)
{
for (z = y + 1; z < 9; z++)
	
{
if (z > y && y > x)
}
{
putchar('0' + x);
putchar('0' + y);
putchar('0' + z);

if (x != 7 || y != 8 || z != 9)
{
putchar(',');
putchar(' ');
}
}
}
}

putchar('\n');
return (0);
}
