// ------------------------------------------------ CustomerScanner.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef CUSTOMERSCANNER_H
#define CUSTOMERSCANNER_H
#include <iostream>
#include <list>
#include <fstream>
#include "Scanner.h"
#include "CustomerRecords.h"
using namespace std;

class CustomerScanner : public Scanner<Customer>
{
public:
	CustomerScanner(CustomerRecords&);			// default constructor
	~CustomerScanner();							// destructor

private:
	CustomerRecords* customers;

	void readFile(list<Customer>&, ifstream&);		// TODO: pass in a list???
};
#endif