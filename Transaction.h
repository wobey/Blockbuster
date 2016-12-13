// ------------------------------------------------ Transaction.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
using namespace std;

class Transaction
{
public:
	Transaction() {}							// default constructor
	virtual ~Transaction() {}					// destructor

	virtual void doTransaction() = 0;
};
#endif