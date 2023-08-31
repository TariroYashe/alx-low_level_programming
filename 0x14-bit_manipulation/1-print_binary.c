#include "main.h"

/**
* print_binary - prints the binary equivalent of a decimal number
* @n: is the number to print in binary
*/

void print_binary(unsigned long int n)
{
int count = 0;
unsigned long int c  = 1UL << 63;
/*
* left-shifts value 1 by 63 positions
*& set the 64th bit to 1and all other bits to 0
*/
if (n == 0)
{
_putchar('0');
return;
}
while (c > 0)
{
if (n & c)
{
_putchar ('1');
count++;
}
else if (count)
{
_putchar('0');
}
c >>= 1;
}
}
