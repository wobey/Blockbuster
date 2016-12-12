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
	template <typename T1>
	friend ostream& operator<<(ostream& ostream, const HashTable<T1>& rhs);

public:
	HashTable();							// default constructor
	//HashTable(const HashTable<T>&);
	~HashTable();							// destructor

	//HashTable& operator=(const HashTable<T>&);
	//bool operator==(const HashTable<T>&);
	//bool operator!=(const HashTable<T>&);
	
	int getHash(T*) const;
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
		int key;					// stores the hash table's key to the value
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
			//cout << "i: " << *table[i]->data << endl;

			delete table[i]->data;
			table[i]->data = NULL;
			table[i]->next = NULL;

			delete table[i];
			table[i] = NULL;
		}
	}

	delete[]* table;
}

template<class T>
int HashTable<T>::getHash(T* keyValue) const
{
	return keyValue->hash() % tableSize;
}

template<class T>
bool HashTable<T>::insert(T* customer)
{
	Node* newNode = new Node;
	newNode->data = customer;
	newNode->next = NULL;

	int index = getHash(customer);
	newNode->key = index;

	// TODO: if occupied decide on collision resolution

	table[index] = newNode;

	return true;
}

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
