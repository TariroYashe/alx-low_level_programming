#include <stdio.h>


/**
* add - Adds two integers.
* @a: The first integer.
* @b: The second integer.
*
* Returns: The result of a + b.
*/
int add(int a, int b)
{
return (a + b);
}

/**
* sub - Subtracts two integers.
* @a: The first integer.
* @b: The second integer.
*
* Returns: The result of a - b.
*/
int sub(int a, int b)
{
return (a - b);
}

/**
* mul - Multiplies two integers.
* @a: The first integer.
* @b: The second integer.
*
* Returns: The result of a * b.
*/
int mul(int a, int b)
{
return (a * b);
}

/**
* div - Divides two integers.
* @a: The dividend.
* @b: The divisor.
*
* Returns: The result of a / b (or 0 with an error message if b is 0).
*/
int div(int a, int b)
{
if (b == 0)
{
fprintf(stderr, "Division by zero\n");
return (0);
}
return (a / b);
}

/**
* mod - Computes the modulo of two integers.
* @a: The dividend.
* @b: The divisor.
*
* Returns: The result of a % b (or 0 with an error message if b is 0).
*/
int mod(int a, int b)
{
if (b == 0)
{
fprintf(stderr, "Modulo by zero\n");
return (0);
}
return (a % b);
}

