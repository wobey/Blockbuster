#ifndef DRAMA_H_INCLUDED
#define DRAMA_H_INCLUDED

#include <iostream>

#include "Movie.h"

using namespace std;

class Drama : public Movie
{
	friend ostream& operator<<(ostream&, const Drama&);

public:
	//constructors
	Drama(int ct, string yr, string name, string dir, string gen);
	Drama(const Drama&);
	~Drama();

	// TODO: fix assignClassicCopy to not be required here
	void assignClassicCopy(Drama*) { }		// only serves to not throw errors in BSTree
	bool compareGreater(Drama*);
	bool compareEqual(Drama*);


};
#endif //DRAMA_H_INCLUDED
