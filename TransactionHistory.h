// ------------------------------------------------ TransactionHistory.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef TRANSACTIONHISTORY_H
#define TRANSACTIONHISTORY_H
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

class TransactionHistory
{
public:
	TransactionHistory() {}							// default constructor
	TransactionHistory(const TransactionHistory&);	// constructor
	~TransactionHistory();							// destructor
	
	bool operator==(const TransactionHistory&);
	bool operator!=(const TransactionHistory&);

	bool insert(const string&);
	bool remove(const string&);
	int find(const string&);
	string retrieve(const string&);
	bool isEmpty() const;
	int size() const;
	void clear();

private:
	list<string> transactionHistory;
};
#endif