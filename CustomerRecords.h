#ifndef CUSTOMERRECORDS_H_INCLUDED
#define CUSTOMERRECORDS_H_INCLUDED

#include <iostream>

#include "HashTable.h"
#include "Customer.h"

using namespace std;

class CustomerRecords
{
	friend ostream& operator<<(ostream& output, const CustomerRecords cusrec);

public:
	//constructors
	CustomerRecords();
	CustomerRecords(const CustomerRecords&);
	~CustomerRecords();

	//assigns
	CustomerRecords operator=(const CustomerRecords&);

	//comparitors
	bool operator==(const CustomerRecords&);
	bool operator!=(const CustomerRecords&);

	//modifiers
	void insert(Customer*);
	void remove(const Customer&);
	Customer* find(string custId) const;
	Customer retrieve(const int) const;

	//other
	bool isEmpty() const;
	int size() const;
	void clear();

private:
	//data
	HashTable<Customer> table;

};
#endif //CUSTOMERRECORDS_H_INCLUDED
