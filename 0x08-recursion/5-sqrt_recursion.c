#include "main.h"
#include <stdio.h>

/**
* sqrt1 - calculates normal sqaure root
* @i: same number as n
* @j: number that iterates from 1 to n
* Return: 1 On success
* -1 on error
*/

int sqrt1(int i, int j)
{
if (j * j == i)
return (j);
else if (j * j > i)
return (-1);
return (sqrt1(i, j + 1));
}

/**
* _sqrt_recursion - returns the natural square root of n
* @n: Integer
* Return: 1 On success
* -1 On error
*/

int _sqrt_recursion(int n)

{
return (sqrt1(n, 1));
}
