#include "main.h"
/**
 * main - print alphabet
 * Description: function that prints the alphabet in lowercase.
 * Return: always 0
 */

void print_alphabet(void)

{
char l;

for (l = 'a'; l <= 'z'; l++)

{
_putchar(l);
}

_putchar('\n');
}
