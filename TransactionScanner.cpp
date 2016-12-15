//#include "stdafx.h"
#include "TransactionScanner.h"

TransactionScanner::TransactionScanner(ifstream& ifstream)
{
	transactions = TransactionHistory();
	readFile(ifstream);
}

TransactionScanner::~TransactionScanner() { }

void TransactionScanner::readFile(ifstream& ifstream)
{
	// implement code to read stream
}
