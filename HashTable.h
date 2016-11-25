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
using namespace std;

static const int MAX_BUCKETS = 1001;	// TODO: decide on a valid initial size

template <typename T>
class HashTable
{
public:
	HashTable();							// default constructor
	HashTable(const HashTable<T>&);
	~HashTable();							// destructor

	HashTable& operator=(const HashTable<T>&);
	bool operator==(const HashTable<T>&);
	bool operator!=(const HashTable<T>&);
	
	bool insert(const T&);
	bool remove(const T&);
	int find(const T&) const;
	T* retrieve(const T&) const;
	bool isEmpty() const;
	int size() const;
	void clear();
	int hash(T&, int);

private:
	T[MAX_BUCKETS] table;
	int numNodes;
};
#endif