#ifndef COMEDY_H_INCLUDED
#define COMEDY_H_INCLUDED

#include <iostream>

#include "Movie.h"

using namespace std;

class Comedy : public Movie
{
	friend ostream& operator<<(ostream& output, const Comedy com);

public:
	//constructors
	Comedy(int ct, int yr, string name, string dir);
	Comedy(const Comedy&);
	~Comedy();

};
#endif //COMEDY_H_INCLUDED
