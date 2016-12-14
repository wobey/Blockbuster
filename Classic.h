#ifndef CLASSIC_H_INCLUDED
#define CLASSIC_H_INCLUDED

#include <iostream>

#include "Movie.h"

using namespace std;

class Classic : public Movie
{
	friend ostream& operator<<(ostream&, Classic);

public:
	//constructors
	Classic(int ct, string yr, string name, string dir, string actorFirst, string actorLast, string mon);
	~Classic();

	//assignment
	Classic operator=(Classic&);

	//comparison
	bool operator==(Classic&);
	bool operator!=(Classic&);
	bool operator>(Classic&);

	//get and set
	string getActorFirst();
	string getActorLast();
	string getMonth();

	void setActorFirst(string);
	void setActorLast(string);
	void setMonth(string);

private:
	//data
	string actorFirst;
	string actorLast;
	string month;

};
#endif// CLASSIC_H_INCLUDED
