#ifndef COMEDY_H_INCLUDED
#define COMEDY_H_INCLUDED

#include <iostream>

#include "Movie.h"

using namespace std;

class Comedy : public Movie
{
	friend ostream& operator<<(ostream&, Comedy&);

public:
	//constructors
	Comedy() { }
	Comedy(int ct, int yr, string name, string dir, string gen);
	Comedy(const Comedy&);
	~Comedy();

	// TODO: fix assignClassicCopy to not be required here
	void assignClassicCopy(Comedy*) { }		// only serves to not throw errors in BSTree
	bool compareGreater(Comedy*);
	bool compareEqual(Comedy*);

};
#endif //COMEDY_H_INCLUDED
