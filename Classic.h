#ifndef CLASSIC_H_INCLUDED
#define CLASSIC_H_INCLUDED

#include <iostream>

#include "Movie.h"

using namespace std;

class Classic : public Movie
{
	friend ostream& operator<<(ostream&, Classic&);

public:
	//constructors
	Classic() {}
	Classic(int ct, int yr, string name, string dir, string actorFirst, string actorLast, int mon, string gen);
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
	int getMonth();

	void setActorFirst(string);
	void setActorLast(string);
	void setMonth(int);

	void assignClassicCopy(Classic*);
	bool compareGreater(Classic*);
	bool compareEqual(Classic*);

private:
	//data
	string actorFirst;
	string actorLast;
	int month;
	Classic* classicCopy;		// only used for classics (is set from within BSTree)
};
#endif// CLASSIC_H_INCLUDED
