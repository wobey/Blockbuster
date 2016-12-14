// ------------------------------------------------ Scannner.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef SCANNERS_H
#define SCANNERS_H
#include <iostream>
#include <list>
#include <fstream>
#include "CustomerScanner.h"
#include "MediaScanner.h"
#include "TransactionScanner.h"
using namespace std;

class Scanners
{
public:
	Scanners() { }
	Scanners(fstream&, fstream&, fstream&);			// constructor
	~Scanners();		// destructor

	void readFiles(fstream&, fstream&, fstream&);

private:
	bool readFile(fstream&, string);

	CustomerScanner customerScanner;
	MediaScanner mediaScanner;
	TransactionScanner transactionScanner;
};
#endif