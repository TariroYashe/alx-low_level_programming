#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: is a string containing the binary number.
 * Return: the converted number, or 0 if invalid input
 */

unsigned int binary_to_uint(const char *b)
{
	int index = 0;
	unsigned int decimal_value = 0;

	if (!b)
		return (0);
	while (b[index] != '\0')
	{
		if (b[index] < '0' || b[index] > '1')
			return (0);

		decimal_value = 2 * decimal_value + (b[index] - '0');
		index++;
	}

	return (decimal_value);
}
