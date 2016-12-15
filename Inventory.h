#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include "Transaction.h"
#include "MediaLibrary.h"

using namespace std;

class Inventory : public Transaction
{
public:
	Inventory(MediaLibrary&);
	~Inventory();

private:

};
#endif //INVENTORY_H_INCLUDED
