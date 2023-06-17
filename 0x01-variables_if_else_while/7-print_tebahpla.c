#include <stdio.h>

/**
 * main - entry point
 *
 * Description: alphabet in reverse order
 *
 * Return: always 0
 */

int main(void)

{
char hpla;

for (hpla = 'z'; hpla >= 'a'; hpla--)

{
putchar(hpla);
}

putchar('\n');

return (0);

}
