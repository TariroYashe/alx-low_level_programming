#include "main.h"

/**
* _isdigit - checks if the input integer variable is a digit
* @c: variable character input
*
* Description: "a function that checks for a digit (0 through 9)."
*
* Return: return 1 if digit and 0 if not
*/

int _isdigit(int c)
{
if (c >= 48 && c <= 57)
{
return (1);
}
else
{
return (0);
}
}
