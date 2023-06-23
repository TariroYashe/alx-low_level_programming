#include "main.h"

/**
* print_line -  a function that draws a straight line in the terminal.
* @n: n is the num of times
*
* Description: "a function that draws a straight line in the terminal."
*
* Return: A line of characters
*/

void print_line(int n)
{
int count;

count = 0;
while (count < n)
{
if (n <= 0)
{
_putchar('\n');
}
else
{
_putchar(95);
count++;
}
}
_putchar('\n');
}
