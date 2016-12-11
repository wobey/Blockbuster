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
	Classic(int ct, int yr, string name, string dir, string actorFirst, string actorLast, int mon);
	~Classic();

	//assignment
	Classic operator=(Classic&);
	Classic operator+(int);

	//comparison
	bool operator==(Classic&);
	bool operator!=(Classic&);
	bool operator>(Classic&);

	//get and set
	string getActorFirst();
	string getActorLast();
	int getMonth();

	void setActorFirst(string);
	void setActorLast(string);
	void setMonth(int);

private:
	//data
	string actorFirst;
	string actorLast;
	int month;

};
#endif// CLASSIC_H_INCLUDED
