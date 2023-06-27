#include "main.h"

/**
* print_last_digit - prints last digit of a value
* @val: value with the last digit
*
* Description: "program prints last digit of a value"
*
* Return: Always last digit of a number (Success)
*/

int print_last_digit(int val)
{
int lastDigit;

lastDigit = val % 10;

if (val <= 0)
{
_putchar(-lastDigit + 48);
return (-lastDigit);
}
else
{
_putchar(lastDigit + 48);
return (lastDigit);
}
}
