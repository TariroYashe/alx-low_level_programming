#include "main.h"

/**
* get_endianness - checks if a machine is little or big endian
* Return: 0 for big endian, 1 for little endaian
*/
int get_endianness(void)
{
unsigned int i = 1;
char *c = (char *)&i;

return ((*c == 1) ? 1 : 0);
}

