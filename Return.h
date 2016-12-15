#ifndef RETURN_H_INCLUDED
#define RETURN_H_INCLUDED

#include "Transaction.h"
#include "MediaLibrary.h"
#include "CustomerRecords.h"

using namespace std;

class Return : public Transaction
{
public:
	//constructors
	Return(MediaLibrary &lib, CustomerRecords *custTable, string custId, string media, string genre, string title, string dir, string actorFirst,
		string actorLast, int month, int yr);
	~Return();

private:
	//other
	void doTransaction(MediaLibrary &lib, CustomerRecords *custTable, string custId, string media, string genre, string title, string dir,
		string actorFirst, string actorLast, int month, int yr);

};
#endif //RETURN_H_INCLUDED
