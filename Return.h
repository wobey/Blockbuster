// ------------------------------------------------ Return.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef RETURN_H
#define RETURN_H
#include <iostream>
#include "Transaction.h"
#include "MediaLibrary.h"
using namespace std;

class Return : public Transaction
{
public:
	Return();							// default constructor
	Return(string&, MediaLibrary&);
	~Return();							// destructor

private:
	void doTransaction();
};
#endif