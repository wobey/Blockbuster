#include "stdafx.h"
#include "CustomerRecords.h"


CustomerRecords::CustomerRecords()
{
}

CustomerRecords::CustomerRecords(const CustomerRecords &)
{
}


CustomerRecords::~CustomerRecords()
{
}

CustomerRecords CustomerRecords::operator=(const CustomerRecords &)
{
	return CustomerRecords();
}

bool CustomerRecords::operator==(const CustomerRecords &)
{
	return false;
}

bool CustomerRecords::operator!=(const CustomerRecords &)
{
	return false;
}

void CustomerRecords::insert(Customer *cust)
{

}

void CustomerRecords::remove(const Customer &)
{
}

Customer* CustomerRecords::find(string custId) const
{
	return NULL;
}

Customer CustomerRecords::retrieve(const int) const
{
	return Customer();
}

bool CustomerRecords::isEmpty() const
{
	return false;
}

int CustomerRecords::size() const
{
	return 0;
}

void CustomerRecords::clear()
{
}
