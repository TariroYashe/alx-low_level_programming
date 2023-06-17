#include <stdio.h>

/**
 * main - entry point
 *
 * Description : programme that print alphabet, lower and upper case.
 *
 * Return: always 0
 */

int main(void)

{
char alpha[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int index;

for (index = 0; index < 52; index++)

{
putchar(alpha[index]);
}

putchar('\n');

return (0);
}
