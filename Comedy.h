// ------------------------------------------------ Comedy.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef COMEDY_H
#define COMEDY_H
#include <string>
#include <iostream>
#include "Movie.h"
using namespace std;

class Comedy : public Movie
{
	friend ostream& operator<<(ostream&, const Comedy&);

public:
	Comedy();							// default constructor
	~Comedy();
	Comedy(int&, int&, string&, string&, string&);
	Comedy(const Comedy&);				// copy constructor

	Comedy& operator=(const Comedy&);
	bool operator==(const Comedy&) const;
	bool operator!=(const Comedy&) const;
};
#endif