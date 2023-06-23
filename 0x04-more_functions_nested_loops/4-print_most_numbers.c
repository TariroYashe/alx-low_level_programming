#include "main.h"

/**
* print_most_numbers - prints numbers except 2 and 4
*
* Description: "a function that print the numbers, from 0 to 9"
*
* Return: return nums except 2 and 4
*
*/

void print_most_numbers(void)
{
int dig;

for (dig = 48; dig <= 57; dig++)
{
if (dig == 50 || dig == 52)
{
continue;
}
else
{
_putchar(dig);
}
}
_putchar('\n');
}
