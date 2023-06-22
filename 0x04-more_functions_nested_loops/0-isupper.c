#include "main.h"

/**
 *_isupper - checks for lowercase character
 * @c: the character to be checked
 * Description: a function that checks for uppercase character
 * Return: 1 for uppercase or 0 otherwis
 */

int _isupper(int c)
{
if (c >= 65 && c <= 90)
{
return (1);
}
return (0);
}
