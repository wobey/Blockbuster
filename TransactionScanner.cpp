//#include "stdafx.h"
#include "TransactionScanner.h"

TransactionScanner::TransactionScanner(fstream& fstream, CustomerRecords* customerRecords, MediaLibrary* mediaLibrary)
{
	readFile(fstream);
}

TransactionScanner::~TransactionScanner() { }

void TransactionScanner::readFile(fstream& fstream)
{
	// implement code to read stream
}
