#include <stdio.h>

/**
 * main - entry point
 *
 * Description: print base 16 numbers and lowercase
 *
 * Return: always 0
 */

int main(void)

{
int b16;

for (b16 = 48; b16 < 58; b16++)
{
putchar(b16);
}

for (b16 = 97; b16 < 103; b16++)
{
putchar(b16);
}

putchar('\n');

return (0);
}
