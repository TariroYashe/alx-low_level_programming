#include "main.h"

/**
* print_rev - function to print a string in reverse.
* @s: used string reference pointer
* Return 0
*/

void print_rev(char *s)
{
int inverse = 0;

while (s[inverse])
inverse++;
while (inverse--)
_putchar(s[inverse]);
_putchar('\n');
}
