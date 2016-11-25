// ------------------------------------------------ Inventory.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include "Transaction.h"
#include "MediaLibrary.h"
using namespace std;

class Inventory : public Transaction
{
public:
	Inventory();							// default constructor
	Inventory(MediaLibrary&);
	~Inventory();							// destructor

private:
	void doTransaction();
};
#endif