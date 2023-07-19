#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - prints each array elements  on a \n.
 * @array: The array.
 * @size: Array size.
 * @action: A pointer to the function to be executed
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array == NULL || action == NULL)
		return;
	while (size-- > 0)
	{
		action(*array);
		array++;
	}
}

