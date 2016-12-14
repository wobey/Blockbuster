#ifndef COMEDY_H_INCLUDED
#define COMEDY_H_INCLUDED

#include <iostream>

#include "Movie.h"

using namespace std;

class Comedy : public Movie
{
	friend ostream& operator<<(ostream&, const Comedy&);

public:
	//constructors
	Comedy(int ct, string yr, string name, string dir);
	Comedy(const Comedy&);
	~Comedy();

	// TODO: fix assignClassicCopy to not be required here
	void assignClassicCopy(Comedy*) { }		// only serves to not throw errors in BSTree
	bool compareGreater(const Comedy*) const;
	bool compareEqual(const Comedy*) const;

};
#endif //COMEDY_H_INCLUDED
