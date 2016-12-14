//#include "stdafx.h"
#include "CustomerScanner.h"

CustomerScanner::CustomerScanner(fstream& fstream)
{
	customers = CustomerRecords();
	readFile(fstream);
}

CustomerScanner::~CustomerScanner() { }

void CustomerScanner::readFile(fstream& fstream)
{
	while (!fstream.eof())
	{
		Customer* customer;

		string id, last, first;

		fstream >> id >> last >> first;
		
		customer = new Customer(id, last, first);

		if (id != "")
			customers.insert(customer);
		else
			delete customer;
	}
	fstream.close();

	cout << customers << endl;
}
