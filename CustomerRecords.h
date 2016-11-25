// ------------------------------------------------ CustomerRecords.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef CUSTOMERRECORDS_H
#define CUSTOMERRECORDS_H
#include <iostream>
#include "Customer.h"
#include "HashTable.h"
using namespace std;

class CustomerRecords
{
public:
	CustomerRecords();							// default constructor
	CustomerRecords(const CustomerRecords&);
	~CustomerRecords();							// destructor

	CustomerRecords& operator=(const CustomerRecords&);
	bool operator==(const CustomerRecords&);
	bool operator!=(const CustomerRecords&);
	bool insert(const Customer&);
	bool remove(const Customer&);
	Customer* find(const string&) const;
	Customer* retrieve(const Customer&) const;
	bool isEmpty() const;
	int size() const;
	void clear();

private:
	HashTable<Customer> customers;
};
#endif