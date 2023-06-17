#include <stdio.h>

/**
 * main - entry point
 *
 * Description: programme that print 0 to 10 in a newline
 *
 * Return: always (0)
 */
int main(void)

{
int index;

for (index = 48; index < 58; index++)

{
putchar(index);
}

putchar('\n');

return (0);

}
