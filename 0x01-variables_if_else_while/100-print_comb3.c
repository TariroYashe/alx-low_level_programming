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
{
for (x = 0; x < 10; x++)
{
for (y = x + 1; y < 10; y++)
{
putchar('0' + x);
putchar('0' + y);

/*if (!(x == 8 && y == 9))*/

if (x != 8 || y != 9)

putchar(',');
putchar(' ');

}
}
}
putchar('\n');
return (0);
}
