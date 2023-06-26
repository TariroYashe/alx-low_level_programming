#include "main.h"

/**
* swap_int - a function that swap two varibles integers
* @a: swaps and stores address of b
* @b: swaps and stores address of a
* Return: always 0
*/

void swap_int(int *a, int *b)

{
int substitute;

substitute = *b;
*b = *a;
*a = substitute;
}
