// ------------------------------------------------ Customer.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include "MediaLibrary.h"
#include "TransactionHistory.h"
using namespace std;

class Customer
{
public:
	Customer();								// default constructor
	Customer(int&, string&, string&);
	Customer(const Customer&);
	~Customer();							// destructor

	Customer& operator=(const Customer&);
	bool operator==(const Customer&);
	bool operator!=(const Customer&);

private:
	int id;
	string lastName;
	string firstName;
	MediaLibrary rentals;
	TransactionHistory history;
};
#endif