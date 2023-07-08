#include "main.h"

/**
* _strlen - checks the length of the string.
* @s: string to be checked
* Return: the length of the string
*/

int _strlen(char *s)
{
int string_measurement = 0;

while (s[string_measurement])
string_measurement++;
return (string_measurement);
}
