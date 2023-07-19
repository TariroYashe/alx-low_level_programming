#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - a function that print name using pointer to function
 * @name: the string name to be printed
 * @f: pointer to function that print the name
 * Return: nothing
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}

