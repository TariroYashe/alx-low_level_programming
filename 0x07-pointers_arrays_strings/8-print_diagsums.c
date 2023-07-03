#include "main.h"
#include <stdio.h>
/**
*print_diagsums - print Σ of two diagonals of the sqr matrix integer
*@a: matrix of integers
*@size: size of matrix
*/

void print_diagsums(int *a, int size)

{
int i, sum_1 = 0, sum_2 = 0;
for (i = 0; i < size; i++)
{
sum_1 += a[i];
a += size;
}

a -= size;
for (i = 0; i < size; i++)
{
sum_2 += a[i];
a -= size;
}
printf("%d, %d\n", sum_1, sum_2);
}
