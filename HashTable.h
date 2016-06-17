/*
hash table to store customers in no particular order.

stores customer objects in this hash table.
*/
#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Customer.h"
#include <string>
#include <iostream>
using namespace std;

class HashTable
{
public:
	HashTable(int);
	~HashTable();
	Customer *get(int);
	void set(int, Customer);

private:
	struct HashEntry
	{
		int key;
		Customer value;
		HashEntry(int k, Customer v)
		{
			key = k;
			value = v;
		}
	};

	const int TABLE_SIZE;
	HashEntry **table;
};

#endif