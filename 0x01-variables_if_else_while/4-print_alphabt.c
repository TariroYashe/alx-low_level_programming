#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - entry point
 *
 * Description:program that prints the alphabet in lowercase without q and e.
 *
 * Return: always 0
 */

int main(void)

{
int index;

for (index = 97; index < 123; index++)

{
if (index != 101 && index != 113)
{
putchar(index);
}
}
putchar('\n');

return (0);
}

