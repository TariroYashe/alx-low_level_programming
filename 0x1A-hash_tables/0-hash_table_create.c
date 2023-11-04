#include "hash_tables.h"

/**
* hash_table_create - Create a hash table
* @size: The size of the array
* Return: A pointer to the newly created hash table, or NULL if an error occurs
*/
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *new_table;
unsigned long int index;

if (size < 1)
return (NULL);

/*Allocate memory for the hash table structure*/
new_table = malloc(sizeof(hash_table_t));
if (new_table == NULL)
return (NULL);

/*Allocate memory for the array of hash_node_t */
new_table->array = malloc(sizeof(hash_node_t *) * size);
if (new_table->array == NULL)
{
free(new_table);
return (NULL);
}

new_table->size = size;
/*Initialize all array elements to NULL*/
for (index = 0; index < size; index++)
new_table->array[index] = NULL;

return (new_table);
}
