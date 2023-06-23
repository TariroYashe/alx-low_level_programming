#include "main.h"

/**
* print_diagonal - a func that draws a diag line
* @n: num of times
*
* Description: "a func that draws a diag line"
*
* Return: diag line
*/

void print_diagonal(int n)
{
int count;
int i;

if (n <= 0)
{
_putchar('\n');
}
else
{
for (count = 0; count < n; count++)
{
for (i = 0; i < count; i++)
{
_putchar(32);
}
_putchar(92);
_putchar('\n');
}
}
}
