// ------------------------------------------------ Borrow.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef BORROW_H
#define BORROW_H
#include <iostream>
#include "Transaction.h"
#include "MediaLibrary.h"
using namespace std;

class Borrow : public Transaction
{
public:
	Borrow();							// default constructor
	Borrow(string&, MediaLibrary&);
	~Borrow();							// destructor

private:
	void doTransaction();
};
#endif