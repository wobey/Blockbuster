// ------------------------------------------------ TransactionScannner.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef TRANSACTIONSCANNER_H
#define TRANSACTIONSCANNER_H
#include <iostream>
#include <list>
#include <fstream>
#include "TransactionHistory.h"
using namespace std;

class TransactionScanner
{
public:
	TransactionScanner() {}				// default constructor
	TransactionScanner(ifstream&);		// constructor
	~TransactionScanner();				// destructor

private:
	TransactionHistory transactions;

	void readFile(ifstream&);		
};
#endif