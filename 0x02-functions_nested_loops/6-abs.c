#include "main.h"

/**
* _abs - computes the absolute val of int
* @n: value to be computed
*
* Description: "computes the absolute value of an integer"
*
* Return: Always absolute value
*
*/

int _abs(int n)
{
if (n >= 0)
{
return (n);
}
else
{
return (-1 * n);
}
_putchar('\n');
}
