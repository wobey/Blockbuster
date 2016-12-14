#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include <iostream>

using namespace std;

class Transaction
{
public:
	//constructors
	Transaction();
	virtual ~Transaction();

private:
	//virtual void doTransaction() = 0;
};
#endif //TRANSACTION_H_INCLUDED
