#include "main.h"
#include <unistd.h>

/**
 * _putchar - print the character c to output
 * 
 * Descriptio: the character to print
 * 
 * Return: on success 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
