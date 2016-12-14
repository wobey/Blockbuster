//#include "stdafx.h"
#include "CustomerRecords.h"


CustomerRecords::CustomerRecords()
{
	if (table != NULL)
		table = new HashTable<Customer>;
}

CustomerRecords::~CustomerRecords()
{
	table->clear();
}

void CustomerRecords::insert(Customer *cust)
{
	table->insert(cust);
}

Customer* CustomerRecords::find(string custId) const
{
	Customer *findCust = table->retrieve(custId);
	return findCust;
}

bool CustomerRecords::isEmpty() const
{
	return table->isEmpty();
}

int CustomerRecords::size() const
{
	return table->getNumEntries();
}

void CustomerRecords::clear()
{
	table->clear();
}

ostream& operator<<(ostream& ostream, const CustomerRecords& rhs)
{
	ostream << *rhs.table;

	return ostream;
}