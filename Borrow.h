#ifndef BORROW_H_INCLUDED
#define BORROW_H_INCLUDED

#include "Transaction.h"
#include "MediaLibrary.h"
#include "CustomerRecords.h"


using namespace std;

class Borrow : public Transaction
{
public:
	// constructors
	Borrow(MediaLibrary &lib, CustomerRecords *custTable, string custId, string media, string genre, string title, string dir, string actorFirst,
		string actorLast, string month, string yr);
	~Borrow();

private:
	void doTransaction(MediaLibrary &lib, CustomerRecords *custTable, string custId, string media, string genre, string title, string dir,
		string actorFirst, string actorLast, string month, string yr);

};
#endif //BORROW_H_INCLUDED
