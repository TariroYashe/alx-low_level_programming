#include "main.h"

/**
* _isalpha - check if a param is alpha
* @c: int arg
*
* Description: "A program that checks if an arg is alpha"
*
* Return: Always 0 (Success)
*
*/

int _isalpha(int c)
{
if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
{
return (1);
}
else
{
return (0);
}

_putchar('\n');
}
