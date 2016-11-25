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
#include "Scanner.h"
#include "TransactionHistory.h"
using namespace std;

class TransactionScanner : public Scanner<string>
{
public:
	TransactionScanner(TransactionHistory&);		// default constructor
	~TransactionScanner();							// destructor

private:
	TransactionHistory* transactions;

	void readFile(list<string>&, ifstream&);		// TODO: pass in a list???
};
#endif