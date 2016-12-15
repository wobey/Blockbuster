#ifndef SCANNERS_H_INCLUDED
#define SCANNERS_H_INCLUDED

#include <iostream>
#include <fstream>
#include "CustomerScanner.h"
#include "MediaScanner.h"
#include "TransactionScanner.h"
using namespace std;

class Scanners
{
	// TODO make Scanners com 
	friend ostream& operator<<(ostream&, const Scanners&);

public:
	//constructors
	Scanners() {}
	Scanners(fstream&, fstream&, fstream&);
	~Scanners();

	void readFiles(fstream&, fstream&, fstream&);

protected:
	bool readFile(fstream&, string);

	CustomerScanner customerScanner; 
	MediaScanner mediaScanner;
	//TransactionScanner transactionScanner;
};
#endif //SCANNERS_H_INCLUDED
