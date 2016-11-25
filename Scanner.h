// ------------------------------------------------ Scannner.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef SCANNER_H
#define SCANNER_H
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

template <typename T>
class Scanner
{
public:
	Scanner();				// default constructor
	virtual ~Scanner();		// destructor

private:
	virtual void readFile(list<T>&, ifstream&);	// TODO: pure virtual???
};
#endif