#include "hash_tables.h"

/**
 * shash_table_create - Create a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created sorted hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *new_table;
    unsigned long int i;

    if (size < 1)
        return (NULL);

    new_table = malloc(sizeof(shash_table_t));
    if (new_table == NULL)
        return (NULL);

    new_table->size = size;
    new_table->array = malloc(sizeof(shash_node_t *) * size);
    if (new_table->array == NULL)
    {
        free(new_table);
        return (NULL);
    }

    new_table->shead = NULL;
    new_table->stail = NULL;
    for (i = 0; i < size; i++)
        new_table->array[i] = NULL;

    return (new_table);
}
/**
 * shash_table_set - Insert a key/value pair into the sorted hash table
 * @ht: The sorted hash table
 * @key: The key (string)
 * @value: The value associated with the key (string)
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *current, *prev = NULL;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    current = ht->array[index];

    while (current)
    {
        int cmp = strcmp(current->key, key);
        if (cmp == 0)
        {
            free(current->value);
            current->value = strdup(value);
            return (1);
        }
        else if (cmp > 0)
        {
            new_node = malloc(sizeof(shash_node_t));
            if (new_node == NULL)
                return (0);

            new_node->key = strdup(key);
            if (new_node->key == NULL)
            {
                free(new_node);
                return (0);
            }
            new_node->value = strdup(value);
            if (new_node->value == NULL)
            {
                free(new_node->key);
                free(new_node);
                return (0);
            }
            new_node->next = current;
            if (prev == NULL)
            {
                ht->array[index] = new_node;
                new_node->sprev = NULL;
                new_node->snext = ht->shead;
                if (ht->shead)
                    ht->shead->sprev = new_node;
                ht->shead = new_node;
            }
            else
            {
                prev->next = new_node;
                new_node->sprev = prev;
                new_node->snext = current;
                if (current)
                    current->sprev = new_node;
            }
            return (1);
        }
        prev = current;
        current = current->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }
    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }
    new_node->next = NULL;
    if (prev == NULL)
    {
        ht->array[index] = new_node;
        new_node->sprev = NULL;
        new_node->snext = ht->shead;
        if (ht->shead)
            ht->shead->sprev = new_node;
        ht->shead = new_node;
        ht->stail = new_node;
    }
    else
    {
        prev->next = new_node;
        new_node->sprev = prev;
        new_node->snext = NULL;
        ht->stail = new_node;
    }
    return (1);
}
/**
 * shash_table_get - Retrieve the value associated with a key from the sorted hash table
 * @ht: The sorted hash table
 * @key: The key you are looking for
 *
 * Return: Value associated with the element, or NULL if the key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *current;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->array[index];
    while (current)
    {
        if (strcmp(current->key, key) == 0)
            return (current->value);
        current = current->next;
    }

    return (NULL);
}
/**
 * shash_table_print - Print the sorted hash table using the sorted linked list
 * @ht: The sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->shead;
    while (node)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->snext;
        if (node)
            printf(", ");
    }
    printf("}\n");
}
/**
 * shash_table_print_rev - Print the sorted hash table in reverse order
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->stail;
    while (node)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->sprev;
        if (node)
            printf(", ");
    }
    printf("}\n");
}
/**
 * shash_table_delete - Delete the entire sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *node, *next;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node)
        {
            next = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = next;
        }
    }

    node = ht->shead;
    while (node)
    {
        next = node->snext;
        free(node->key);
        free(node->value);
        free(node);
        node = next;
    }

    free(ht->array);
    free(ht);
}
