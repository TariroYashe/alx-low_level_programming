#include "main.h"

/**
* rot13 - function to encodes a string.
* @str: string
*
* Description: "encodes a string into rot13."
*
* Return: a string
*
*/


char *rot13(char *str)
{
char *ptr = str;

while (*ptr != '\0')
{
char i = *ptr;

if ((i >= 'a' && i <= 'm') || (i >= 'A' && i <= 'M'))
{
*ptr = i + 13;
}
else if ((i >= 'n' && i <= 'z') || (i >= 'N' && i <= 'Z'))
{
*ptr = i - 13;
}

ptr++;
}

return (str);
}
