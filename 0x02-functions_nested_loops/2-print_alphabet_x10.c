#include "main.h"
/**
 * print_alphabet_x10 - repeats the print 10 times
 * Return: 0
 */

void print_alphabet_x10(void)
{
	int j;
	char ch;
	 for (j = 0; j < 10; ++j)
	 {
		  for (ch = 'a'; ch <= 'z'; ch++)
		  {
			  _putchar(ch);
		  }
		  _putchar('\n');
	 }
}

