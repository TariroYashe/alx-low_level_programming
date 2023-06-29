#include "main.h"

/**
** reverse_array - function that reverse the content of an array of integers.
** @p: pointer to array.
** @n: number of array elements.
** Return: void
**/

void reverse_array(int *p, int n)
{
int temp, counter;

n = n - 1;
counter = 0;
while (counter <= n)
{
temp = p[counter];
p[counter++] = p[n];
p[n--] = temp;
}
}
