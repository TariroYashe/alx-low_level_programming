#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - entry point
 *
 * Description: program that prints 1 to 9
 *
 * Return: always 0
 */

int main(void)

{
char [11] = "0123456789";

int index;

for (index = 0; index < 10; index++)

{
printf("%d", index);
}

return (0);

}
