#include <stdio.h>
/**
 * main  - entry pointt
 *
 * Decsription: prints all possible different combinations of two digits
 *
 * Return: always 0
 */

int main(void)

{
int x, y;

for (x = 0; x <= 8; x++)
{
for (y = 1; y <= 9; y++)
{
if (y > x)
{
putchar('0' + x);
putchar('0' + y);

if (x != 8 || y != 9)

putchar(',');
putchar(' ');

}
}
}

return (0);
}

