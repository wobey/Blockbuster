// ------------------------------------------------ HashTable.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <fstream>
using namespace std;

static const int MAX_BUCKETS = 997;

template <typename T>
class HashTable
{
public:
	HashTable();							// default constructor
	//HashTable(const HashTable<T>&);
	~HashTable();							// destructor

	//HashTable& operator=(const HashTable<T>&);
	//bool operator==(const HashTable<T>&);
	//bool operator!=(const HashTable<T>&);
	//
	bool insert(T*);
	//bool remove(const T&);
	//int find(const T&) const;
	//T* retrieve(const T&) const;
	//bool isEmpty() const;
	//int size() const;
	//void clear();
	//int hash(T&, int);

protected:
	struct Node
	{
		T* data;					// pointer to data object
		Node* next;					// pointer to next array Node
	};

	Node** table;
	int tableSize;
	int numberOfEntries;
};
#endif

//---------------------------- DefaultConstructor -------------------------------------
// creates an empty hash table
template <class T>
HashTable<T>::HashTable()
{
	tableSize = MAX_BUCKETS;
	numberOfEntries = 0;

	table = new Node*[tableSize];
	for (int i = 0; i < tableSize; i++)
	{
		table[i] = NULL;
	}
}

template <class T>
HashTable<T>::~HashTable()
{
	for (int i = 0; i < tableSize; i++)
	{
		if (table[i] != NULL)
		{
			delete table[i]->data;
			table[i]->data = NULL;
			table[i]->next = NULL;

			delete table[i];
			table[i] = NULL;
		}
	}

	delete table;
}

template<class T>
bool HashTable<T>::insert(T* customer)
{
	return true;
}