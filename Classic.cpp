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

bool Classic::compareGreater(const Classic* rhs) const
{
	// compare year, month, and major actor
	if (year != rhs->year)
		return std::stoi(year) > std::stoi(rhs->year);
	else if (month != rhs->month)
		return std::stoi(month) > std::stoi(rhs->month);

	string actor1 = actorFirst + actorLast;
	string actor2 = rhs->actorFirst + rhs->actorLast;

	return (actor1).compare(actor2) > 0;
}

bool Classic::compareEqual(const Classic* rhs) const
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