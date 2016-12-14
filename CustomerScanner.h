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
#include "CustomerRecords.h"
using namespace std;

class CustomerScanner
{
public:
	CustomerScanner() {}				// default constructor
	CustomerScanner(ifstream&);			// constructor
	~CustomerScanner();					// destructor

private:
	CustomerRecords customers;

	void readFile(ifstream&);		
};
#endif