#include "main.h"

/**
* *_strcpy - copies the string pointed to by yashe
* @dest: char type string
* @src: char type string
* Descrption:copy a string pointed to by yashe to a buffer pointed to by dest
* Return: Pointer to dest
*/

char *_strcpy(char *dest, char *src)
{
int z = -1;

do {
z++;
dest[z] = src[z];
} while (dest[z] != '\0');

return (src);
}
