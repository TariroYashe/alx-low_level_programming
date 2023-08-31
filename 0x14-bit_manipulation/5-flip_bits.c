#include "main.h"

/**
* flip_bits - function that counts the number of bits to change
* to get from one number to another
* @n: the 1st number
* @m: 2nd number
* Return: The number of bits to change
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
int i, count = 0;
unsigned long int present;
unsigned long int entire = n ^ m;

for (i = 63; i >= 0; i--)
{
present = entire >> i;
if (present & 1)
count++;
}

return (count);
}
