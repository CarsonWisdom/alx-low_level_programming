#include "hash_tables.h"

/**
 * key_index - function that returns the index of a key.
 * @key: pointer to key to get index.
 * @size: size of the array of the hash table.
 *
 * Return: index at which da value pair shld b stored array of hash table.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
