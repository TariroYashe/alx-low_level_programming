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
int index = 0;

while (index < 10)

{putchar(index);
index++;
}

putchar('\n');

return (0);

}
