#ifndef TRANSACTIONHISTORY_H_INCLUDED
#define TRANSACTIONHISTORY_H_INCLUDED

#include <iostream>
#include <queue>

using namespace std;

class TransactionHistory
{

public:
	//constructors
	TransactionHistory();
	~TransactionHistory();

	void insert(string);
	void print();

private:
	queue <string> list;

};
#endif //TRANSACTIONHISTORY_H_INCLUDED
