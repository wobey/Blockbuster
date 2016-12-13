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
	Borrow(MediaLibrary &lib, CustomerRecords custTable, string custId, char media, char genre, string title, string dir, string actorFirst, 
		string actorLast, int month, int yr);
	~Borrow();

private:
	void doTransaction(MediaLibrary &lib, CustomerRecords custTable, string custId, char media, char genre, string title, string dir, 
		string actorFirst, string actorLast, int month, int yr);

};
#endif //BORROW_H_INCLUDED
