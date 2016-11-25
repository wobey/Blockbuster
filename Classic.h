// ------------------------------------------------ Classic.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef CLASSIC_H
#define CLASSIC_H
#include <string>
#include <iostream>
#include "Movie.h"
using namespace std;

class Classic : public Movie
{
	friend ostream& operator<<(ostream&, const Classic&);

public:
	Classic();							// default constructor
	~Classic();
	Classic(int&, int&, string&, string&, string&, string&, int&, string&);
	Classic(const Classic&);			// copy constructor

	Classic& operator=(const Classic&);
	bool operator==(const Classic&) const;
	bool operator!=(const Classic&) const;

private:
	string actorFirstName;
	string actorLastName;
	int month;
};
#endif