#include "function_pointers.h"
/**
 * int_index -  search for an integer in an array of int.
 * @array: array of int
 * @size: size of array
 * @cmp: a pointer to function to be used to compare values
 * Return: If no element matches, return -1 ; If size <= 0, return -1
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}

