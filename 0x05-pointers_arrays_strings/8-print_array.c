#include <stdio.h>

/**
* print_array - fucntion that print elements of and array and new line.
* @i: is an input array
* @l: is the length of the array
*/

void print_array(int *i, int l)
{
int indicator_of_array;
for (indicator_of_array = 0; indicator_of_array < l; indicator_of_array++)
{
printf("%d", i[indicator_of_array]);
if (indicator_of_array != (l - 1))

{
printf(", ");
}
}
putchar('\n');
}

