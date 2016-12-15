//#include "stdafx.h"
#include "Classic.h"


Classic::Classic(int ct, int yr, string name, string dir, string first, string last, int mon, string gen): Movie(ct, yr, name, dir, gen)
{
	setStock(ct);
	setYear(yr);
	setTitle(name);
	setDirector(dir);
	actorFirst = first;
	actorLast = last;
	month = mon;
	classicCopy = NULL;
} //end Classic

Classic::~Classic() { }

string Classic::getActorFirst()
{
	return actorFirst;
}

string Classic::getActorLast()
{
	return actorLast;
}

int Classic::getMonth()
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

void Classic::setMonth(int mon)
{
	month = mon;
}

bool Classic::compareGreater(Classic* rhs)
{
	// compare year, month, and major actor
	if (year != rhs->year)
		return year > rhs->year;
	else if (month != rhs->month)
		return month > rhs->month;

	string actor1 = actorFirst + actorLast;
	string actor2 = rhs->actorFirst + rhs->actorLast;

	return (actor1).compare(actor2) > 0;
}

bool Classic::compareEqual(Classic* rhs)
{
	string actor1 = actorFirst + actorLast;
	string actor2 = rhs->actorFirst + rhs->actorLast;

	if (year == rhs->year && (actor1).compare(actor2) == 0 && month == rhs->month)
		return true;
	else
		return false;
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

void Classic::assignClassicCopy(Classic* movie)
{
	classicCopy = movie;
}

ostream& operator<<(ostream& output, Classic &cls)
{
	output << "Title: " << cls.getTitle() << " / Director: " << cls.getDirector() << ", Month: " << cls.getMonth() << ", Year: " << cls.getYear() << ", Stock: " << cls.getStock() << endl;
	output << "Actor: " << cls.getActorFirst() << " " << cls.getActorLast() << endl;
	return output;
}