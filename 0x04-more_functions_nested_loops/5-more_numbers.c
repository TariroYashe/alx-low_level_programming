#include "main.h"

/**
* more_numbers - a function that prints 10 times the numbers
*
* Description: "a function that prints 10 times the numbers"
*
*/

void more_numbers(void)
{
int num;
int counter;

for (counter = 1; counter <= 10; counter++)
{
for (num = 0; num <= 14; num++)
{
if (num >= 10)
_putchar('1');
_putchar(num % 10 + '0');
}
_putchar('\n');
}
}
