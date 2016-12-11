#ifndef DRAMA_H_INCLUDED
#define DRAMA_H_INCLUDED

#include <iostream>

#include "Movie.h"

using namespace std;

class Drama : public Movie
{
	friend ostream& operator<<(ostream& output, Drama &drm);

public:
	//constructors
	Drama(int ct, int yr, string name, string dir);
	Drama(const Drama&);
	~Drama();

};
#endif //DRAMA_H_INCLUDED
