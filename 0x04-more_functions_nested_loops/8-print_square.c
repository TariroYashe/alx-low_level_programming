#include "main.h"

/**
* print_square -  a function that prints a square
* @size:  size of the square
*
* Description: " a function that prints a square"
*
* Return: square
*/

void print_square(int size)
{
int i;
int count;

if (size <= 0)
{
_putchar('\n');
}
else
{
for (i = 0; i < size; i++)
{
for (count = 0; count < size; count++)
{
_putchar('#');
}
_putchar('\n');
}
}
}
