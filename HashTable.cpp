#include "stdafx.h"
#include "HashTable.h"


HashTable::HashTable()
{
}

template<class Comparable>
HashTable<Comparable>::HashTable(const HashTable &)
{
}


HashTable::~HashTable()
{
}

template<class Comparable>
HashTable<Comparable>& HashTable<Comparable>::operator=(const HashTable<Comparable>&)
{
	// TODO: insert return statement here
}

template<class Comparable>
bool HashTable<Comparable>::operator==(const HashTable<Comparable>&)
{
	return false;
}

template<class Comparable>
bool HashTable<Comparable>::operator!=(const HashTable<Comparable>&)
{
	return false;
}

template<class Comparable>
void HashTable<Comparable>::insert(const Comparable &)
{
}

template<class Comparable>
void HashTable<Comparable>::remove(const Comparable &)
{
}

template<class Comparable>
int HashTable<Comparable>::find(const Comparable &) const
{
	return 0;
}

template<class Comparable>
Comparable HashTable<Comparable>::retrieve(const int) const
{
	return Comparable();
}

template<class Comparable>
bool HashTable<Comparable>::isEmpty() const
{
	return false;
}

template<class Comparable>
int HashTable<Comparable>::size() const
{
	return 0;
}

template<class Comparable>
void HashTable<Comparable>::clear()
{
}

template<class Comparable>
int HashTable<Comparable>::hash(Comparable, int)
{
	return 0;
}
