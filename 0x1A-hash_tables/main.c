#include <stdio.h>
#include "hash_tables.h"

/**
* main - Entry point for the program
*
* Return: Always EXIT_SUCCESS.
*/
int main(void)
{
hash_table_t *ht;
char *key1 = "betty";
char *value1 = "cool";

ht = hash_table_create(1024);
if (ht == NULL)
{
fprintf(stderr, "Failed to create the hash table\n");
return (EXIT_FAILURE);
}

if (hash_table_set(ht, key1, value1) == 0)
{
fprintf(stderr, "Failed to set key-value pair in the hash table\n");
hash_table_delete(ht);
return (EXIT_FAILURE);
}

printf("Value for key '%s': %s\n", key1, hash_table_get(ht, key1));

hash_table_delete(ht);

return (EXIT_SUCCESS);
}
