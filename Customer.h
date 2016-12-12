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
#include <fstream>
#include "MediaLibrary.h"
#include "TransactionHistory.h"
using namespace std;

class Customer
{
	friend ostream& operator<<(ostream& ostream, const Customer& rhs);

public:
	Customer();								// default constructor
	Customer(string, string, string);
	Customer(const Customer&);
	~Customer();							// destructor

	string getID() const;
	string getFirstName() const;
	string getLastName() const;

	int hash() const;
	Customer& operator=(const Customer&);
	bool operator==(const Customer&);
	bool operator!=(const Customer&);

private:
	string id;
	string firstName;
	string lastName;
	//MediaLibrary rentals;
	//TransactionHistory history;
};
#endif