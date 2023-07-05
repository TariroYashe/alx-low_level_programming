#include "main.h"

/**
* prime1 - evaluates from 1 to n
* @i: same number as n
* @j: number that iterates from 1 to n
* Return: 1 On success
* -1 On error
*/

int prime1(int i, int j)

{
if (i == j)
return (1);

else if (i % j == 0)
return (0);
return (prime1(i, j + 1));
}

/**
*is_prime_number -  returns 1 if the input integer is a prime number
*@n: the integer
*Return: 1 if prime number, 0 if otherwise
*/

int is_prime_number(int n)

{
int is_prime_number(int n);

if (n <= 1)
return (0);
return (prime1(n, 2));
}
