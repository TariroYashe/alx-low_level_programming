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

/**
* hash_table_create - Creates a hash table
* @size: The size of the array
*
* Return: A pointer to the newly created hash table, or NULL if an error occurs
*/
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *new_table;
unsigned long int i;

if (size <= 0)
return (NULL);

new_table = malloc(sizeof(hash_table_t));
if (new_table == NULL)
return (NULL);

new_table->size = size;
new_table->array = malloc(sizeof(hash_node_t *) * size);
if (new_table->array == NULL)
{
free(new_table);
return (NULL);
}

for (i = 0; i < size; i++)
{
new_table->array[i] = NULL;
}

return (new_table);
}
