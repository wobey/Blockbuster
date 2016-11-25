// ------------------------------------------------ History.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H
#include <iostream>
#include "Transaction.h"
#include "MediaLibrary.h"
using namespace std;

class History : public Transaction
{
public:
	History();							// default constructor
	History(string&, MediaLibrary&);
	~History();							// destructor

private:
	void doTransaction();
};
#endif