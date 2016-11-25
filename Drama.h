// ------------------------------------------------ Drama.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef DRAMA_H
#define DRAMA_H
#include <string>
#include <iostream>
#include "Movie.h"
using namespace std;

class Drama : public Movie
{
	friend ostream& operator<<(ostream&, const Drama&);

public:
	Drama();							// default constructor
	~Drama();
	Drama(int&, int&, string&, string&, string&);
	Drama(const Drama&);				// copy constructor

	Drama& operator=(const Drama&);
	bool operator==(const Drama&) const;
	bool operator!=(const Drama&) const;
};
#endif