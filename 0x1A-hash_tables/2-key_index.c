#include "hash_tables.h"

/**
 * key_index - Get the index of a key in a hash table array.
 * @key: The key (string) to be hashed.
 * @size: The size of the hash table array.
 *
 * Return: The index at which the key should be stored in the array.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

    /*Calculate the hash value using the djb2 hash function*/
	hash_value = hash_djb2(key);

    /*Use modulo to map the hash value to a valid index within the array size*/
	return (hash_value % size);
}
