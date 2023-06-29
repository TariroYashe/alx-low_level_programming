#include "main.h"

/**
* string_toupper - function that changes lowercases of a string to uppercase.
* @p: pointer to string.
* Return: pointer to uppercase string.
*/

char *string_toupper(char *p)
{
int string_length;
string_length = 0;

while (p[string_length] != '\0')
{
if (p[string_length] >= 97 && p[string_length] <= 122)
{
p[string_length] = p[string_length] - 32;
}
string_length++;
}
return (p);
}
