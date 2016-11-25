// ------------------------------------------------ TransactFactory.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef TRANSACTFACTORY_H
#define TRANSACTFACTORY_H
#include <iostream>
using namespace std;

class TransactFactory
{
public:
	TransactFactory();							// default constructor
	~TransactFactory();							// destructor

	static string CreateTransaction(string&);
};
#endif