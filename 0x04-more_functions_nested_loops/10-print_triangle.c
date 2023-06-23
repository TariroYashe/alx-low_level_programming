#include "main.h"

/**
* print_triangle - a func that draws a triangle
* @size: num of times
*
* Description: "a func that draws a triangle"
*
* Return: triangle
*/

void print_triangle(int size)
{
int count;
int i;
int j;

if (size <= 0)
{
_putchar('\n');
}
else
{
for (count = 1; count <= size; count++)
{
for (i = size - count; i >= 1; i--)
{
_putchar(32);
}
for (j = 1; j <= count; j++)
{
_putchar(35);
}
_putchar('\n');
}
}
}
