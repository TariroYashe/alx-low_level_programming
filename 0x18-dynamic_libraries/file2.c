#include "main.h"

/**
* _isdigit - Checks if a character is a digit (0-9)
* @c: The character to check
*
* Return: 1 if the character is a digit, 0 otherwise
*/
int _isdigit(int c)
{
return (c >= '0' && c <= '9');
}

/**
* _strlen - Calculates the length of a string
* @s: The string to measure
*
* Return: The length of the string
*/
int _strlen(char *s)
{
int len = 0;
while (s[len] != '\0')
{
len++;
}
return (len);
}

/**
* _puts - Prints a string to the standard output
* @s: The string to print
*/
void _puts(char *s)
{
int i = 0;
while (s[i] != '\0')
{
_putchar(s[i]);
i++;
}
}

/**
* _strcpy - Copies a string to another
* @dest: The destination string
* @src: The source string
*
* Return: A pointer to the destination string
*/
char *_strcpy(char *dest, char *src)
{
int i = 0;
while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}

/**
* _atoi - Converts a string to an integer
* @s: The string to convert
*
* Return: The integer value from the string
*/
int _atoi(char *s)
{
int result = 0;
int sign = 1;
int i = 0;

if (s[0] == '-')
{
sign = -1;
i++;
}

while (s[i] != '\0')
{
if (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');
}
else
{
break;/*Break on encountering a non-digit character*/
}
i++;
}

return (sign *result);
}

