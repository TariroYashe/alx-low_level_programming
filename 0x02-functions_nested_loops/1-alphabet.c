#include "main.h"
/**
 * main - print alphabet
 * print_alphabet - prints the english alphabet from a-z
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
