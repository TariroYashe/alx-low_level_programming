#include "main.h"

/**
* *_strcpy - copies the string pointed to by yashe
* @tariro: char type string
* @yashe: char type string
* Descrption:copy a string pointed to by yashe to a buffer pointed to by tariro
* Return: Pointer to tariro
*/

char *_strcpy(char *tariro, char *yashe)
{
int z = -1;

do {
z++;
tariro[z] = yashe[z];
} while (yashe[z] != '\0');

return (tariro);
}
