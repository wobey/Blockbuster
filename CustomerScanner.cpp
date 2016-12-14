//#include "stdafx.h"
#include "CustomerScanner.h"

CustomerScanner::CustomerScanner(ifstream& ifstream)
{
	customers = CustomerRecords();
	readFile(ifstream);
}

CustomerScanner::~CustomerScanner() { }

void CustomerScanner::readFile(ifstream& ifstream)
{
	// implement code to read stream
}
