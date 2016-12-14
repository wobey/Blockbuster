#ifndef HISTORY_H_INCLUDED
#define HISTORY_H_INCLUDED

#include "Transaction.h"
#include "CustomerRecords.h"

using namespace std;

class History : public Transaction
{
public:
	//constructors
	History();
	History(string, CustomerRecords&);
	~History();

private:

};
#endif// HISTORY_H_INCLUDED
