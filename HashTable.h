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
#include "Customer.h"	// need for g++
using namespace std;

static const int MAX_BUCKETS = 997;

template <class T>
class HashTable
{
	template <class T1>
	friend ostream& operator<<(ostream&, const HashTable<T1>&);

public:
	HashTable();							// default constructor
	~HashTable();							// destructor
	
	int getHash(const T*) const;
	bool insert(T*);
	//bool erase(T*);		// never used
	bool entryExists(const string) const;
	bool entryExists(const T*) const;
	//int find(const T&) const;
	T* retrieve(const string);
	T* retrieve(const T*);
	bool isEmpty() const;
	int getNumEntries() const;
	void clear();

protected:
	struct Node
	{
		T* data;					// pointer to data object
		int key;					// stores the hash table's key to the value
		Node* next;					// pointer to next array Node
	};

	Node** table;					// the hash table
	int tableSize;					// the size of the hash table array
	int numberOfEntries;			// the number of entries in the hash table
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

//---------------------------- destructor -------------------------------------
// deletes contents of hash table by calling clear()
template <class T>
HashTable<T>::~HashTable()
{
	clear();
}

//---------------------------- getHash -------------------------------------
// returns the hash key of the item
template<class T>
int HashTable<T>::getHash(const T* keyValue) const
{
	string key = keyValue->getID();

	return keyValue->hash(key) % tableSize;
}

//---------------------------- insert -------------------------------------
// insert an item into the hash table
template<class T>
bool HashTable<T>::insert(T* customer)
{
	Node* newNode = new Node;
	newNode->data = customer;
	newNode->next = NULL;

	int index = getHash(customer);
	newNode->key = index;

	// TODO: if occupied decide on collision resolution (not necessary for submission)

	table[index] = newNode;
	numberOfEntries++;

	return true;
}

//---------------------------- erase -------------------------------------
// erases an item from the hash table
//template<class T>
//bool HashTable<T>::erase(T* customer)
//{
//
//	numberOfEntries--;
//	return true;
//}

//---------------------------- entryExists -------------------------------------
// determines if the user id is contained in the hash table using a string
template<class T>
bool HashTable<T>::entryExists(const string key) const
{
	int hashIndex = Customer::hash(key) % tableSize;

	if (table[hashIndex] != NULL)
		return true;
	else
		return false;
}

//---------------------------- entryExists -------------------------------------
// determines if the user id is contained in the hash table using customer object
template<class T>
bool HashTable<T>::entryExists(const T* customer) const
{
	if (table[getHash(customer)] != NULL)
		return true;
	else
		return false;
}

//---------------------------- retrieve -------------------------------------
// returns pointer to entry
template<class T>
T* HashTable<T>::retrieve(const string key)
{
	string keyID = key;
	int hashValue = 0;

	for (int i = 0; i < keyID.size(); i++)
		hashValue += keyID[i];

	if (table[hashValue] != NULL)
		return table[hashValue]->data;
	else
		return NULL;
}

//---------------------------- retrieve -------------------------------------
// returns pointer to entry using customer object
template<class T>
T* HashTable<T>::retrieve(const T* customer)
{
	if (table[getHash(customer)] != NULL)
		return table[getHash(customer)]->data;
	else
		return NULL;
}

//---------------------------- isEmpty -------------------------------------
// determines if the hash table has any entries in it
template<class T>
bool HashTable<T>::isEmpty() const
{
	if (getNumEntries() == 0)
		return true;
	else
		return false;
}

//---------------------------- getNumEntries -------------------------------------
// returns the number of entries in the hash table
template<class T>
int HashTable<T>::getNumEntries() const
{
	return numberOfEntries;
}

//---------------------------- clear -------------------------------------
// clears all entries from the hash table
template<class T>
void HashTable<T>::clear()
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

	delete[] table;
}

//---------------------------- operator<< -------------------------------------
// displays the contents of the hash tables
template <class T1>
std::ostream& operator<<(ostream& ostream, const HashTable<T1>& rhs)
{
		for (int i = 1; i < rhs.tableSize; i++)
		{
			if (rhs.table[i] != NULL)
				ostream << "[i=" << i << "] " << *rhs.table[i]->data << endl;
		}

		cout << endl;

		return ostream;
}
