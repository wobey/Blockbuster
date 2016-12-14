//#include "stdafx.h"
#include "Classic.h"


Classic::Classic(int ct, string yr, string name, string dir, string first, string last, string mon): Movie(ct, yr, name, dir)
{
	setStock(ct);
	setYear(yr);
	setTitle(name);
	setDirector(dir);
	actorFirst = first;
	actorLast = last;
	month = mon;
} //end Classic

Classic::~Classic()
{
} //end ~Classic

string Classic::getActorFirst()
{
	return actorFirst;
}

string Classic::getActorLast()
{
	return actorLast;
}

string Classic::getMonth()
{
	return month;
}

void Classic::setActorFirst(string actfirst)
{
	actorFirst = actfirst;
}

void Classic::setActorLast(string actlast)
{
	actorLast = actlast;
}

void Classic::setMonth(string mon)
{
	month = mon;
}

Classic Classic::operator=(Classic &cls)
{
	//duplicate check
	if (*this == cls)
	{
		return *this;
	}

	setStock(cls.getStock());
	setYear(cls.getYear());
	setTitle(cls.getTitle());
	setDirector(cls.getDirector());
	actorFirst = cls.actorFirst;
	actorLast = cls.actorLast;
	month = cls.month;

	return *this;
} //end operator=

bool Classic::operator>(Classic &cls)
{
	if (actorLast == cls.actorLast)
	{
		return actorFirst > cls.actorFirst;
	}
	return actorLast > cls.actorLast;
}

bool Classic::operator==(Classic &cls)
{
	return ((getStock() == cls.getStock()) && (getYear() == cls.getYear()) && (getDirector() == cls.getDirector()) &&
		(actorFirst == cls.actorFirst) && (actorLast == cls.actorLast) && (month == cls.month));
} //end operator==

bool Classic::operator!=(Classic &cls)
{	
	return ((getStock() != cls.getStock()) || (getYear() != cls.getYear()) || (getDirector() != cls.getDirector()) ||
		(actorFirst != cls.actorFirst) || (actorLast != cls.actorLast) || (month != cls.month));
} //end operator!=

ostream& operator<<(ostream& output, Classic &cls)
{
	output << "Title: " << cls.getTitle() << " / Director: " << cls.getDirector() << ", Month: " << cls.getMonth() << ", Year: " << cls.getYear() << ", Stock: " << cls.getStock() << endl;
	output << "Actor: " << cls.getActorFirst() << " " << cls.getActorLast() << endl;
	return output;
}