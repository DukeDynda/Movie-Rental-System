/*
hash table to store customer (objects)

HashTable(int)
~HashTable()
Customer *get(int)
void set(int, Customer)
*/
#include "HashTable.h"

HashTable::HashTable(int tableSize) : TABLE_SIZE(tableSize)
{
	table = new HashEntry*[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
		table[i] = NULL;
}

HashTable::~HashTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
		if (table[i] != NULL)
			delete table[i];
	delete[] table;
}

Customer *HashTable::get(int key)
{
	int hash = key % TABLE_SIZE;
	while (table[hash] != NULL && table[hash]->key != key)
		hash = (hash + 1) % TABLE_SIZE;
	Customer *badCustomer = new Customer();
	badCustomer->setID(-1);
	if (table[hash] == NULL)
		return badCustomer;
	else
	{
		delete badCustomer;
		return &table[hash]->value;
	}
}

void HashTable::set(int key, Customer value)
{
	int hash = (key % TABLE_SIZE);
	while (table[hash] != NULL && table[hash]->key != key)
		hash = (hash + 1) % TABLE_SIZE;
	if (table[hash] != NULL)
		delete table[hash];
	table[hash] = new HashEntry(key, value);
}
