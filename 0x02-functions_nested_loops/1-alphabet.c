#include "main.h"

/**
 * main - print_alphabet
 * Description: function that print alphabet
 * Return: always 0
 */
void print_alphabet(void)
{
	char alpha;
	for (alpha  = 'a'; alpha <= 'z'; alpha++)
	{
		 _putchar(alpha);
	}
	
	_putchar('\n');
		
	}
