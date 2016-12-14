//////#include "stdafx.h"
#include "Scanners.h"

Scanners::Scanners(fstream& customerFile, fstream& movieFile, fstream& commandFile)
{ 
	readFiles(customerFile, movieFile, commandFile);
}

Scanners::~Scanners() { }

void Scanners::readFiles(fstream& customerFile, fstream& movieFile, fstream& commandFile)
{
	if (!readFile(customerFile, "Customers"))
		cout << "customer file was not read in correctly" << endl;
	//if (!readFile(movieFile, "Movies"))
	//	cout << "movie file was not read in correctly" << endl;
	//if (!readFile(commandFile, "Commands"))
	//	cout << "command file was not read in correctly" << endl;
}

bool Scanners::readFile(fstream& fstream, string type)
{
	if (type == "Customers")
		customerScanner = CustomerScanner(fstream);
	//if (type == "Movies")
	//
	//if (type == "Commands")

	return true;
}

ostream& operator<<(ostream& ostream, const Scanners& scanner)
{
	// TODO finish stream operator

	return ostream;
}