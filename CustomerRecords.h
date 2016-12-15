#ifndef CUSTOMERRECORDS_H_INCLUDED
#define CUSTOMERRECORDS_H_INCLUDED

#include <iostream>

#include "HashTable.h"
#include "Customer.h"

using namespace std;

class CustomerRecords
{
	friend ostream& operator<<(ostream&, const CustomerRecords);

public:
	//constructors
	CustomerRecords();
	~CustomerRecords();

	//modifiers
	void insert(Customer*);
	Customer* find(string custId) const;

	//other
	bool isEmpty() const;
	int size() const;
	void clear();

private:
	//data
	HashTable<Customer> *table;

};
#endif //CUSTOMERRECORDS_H_INCLUDED
