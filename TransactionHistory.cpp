#include "stdafx.h"
#include "TransactionHistory.h"


TransactionHistory::TransactionHistory()
{
}


TransactionHistory::~TransactionHistory()
{
}

void TransactionHistory::insert(string transaction)
{
	list.push(transaction);
}

void TransactionHistory::print()
{
	string popTrans;
	while (list.size() > 0)
	{
		list.front();
		cout << endl;
		list.pop();
	}
}
