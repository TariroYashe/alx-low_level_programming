#include "hash_tables.h"

/**
* hash_djb2 - Hash function using the DJB2 algorithm
* @str: A pointer to the input string
*
* Return: The hash value for the given string.
*/
unsigned long int hash_djb2(const unsigned char *str)
{
unsigned long int hash;
int c;

hash = 5381;
while ((c = *str++))
{
hash = ((hash << 5) + hash) +c; /* hash * 33 + c */
}
return (hash);
}
