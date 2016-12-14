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
	friend ostream& operator<<(ostream& output, const Scanners com);

public:
	//constructors
	Scanners() {}
	Scanners(fstream&, fstream&, fstream&);
	~Scanners();

	void readFiles(fstream&, fstream&, fstream&);

private:
	bool readFile(fstream&, string);

	CustomerScanner customerScanner;
	MediaScanner mediaScanner;
	TransactionScanner transactionScanner;

};
#endif //SCANNERS_H_INCLUDED
