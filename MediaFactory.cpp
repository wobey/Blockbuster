//#include "stdafx.h"
#include "MediaFactory.h"

Movie* MediaFactory::createMovie(istream& istream)//string type, int stock, string dir, string title, string ryear, string actorFirst, string actorLast, string rmonth)
{
	char type;
	string dir, title, actorFirst, actorLast, genre;
	int stock, ryear, rmonth;

	istream >> type;
	genre = type;

	if (genre == "C")
	{
		setInitialMovie(istream, stock, dir, title);
		setClassic(istream, actorFirst, actorLast, rmonth, ryear);
		return new Classic(stock, ryear, title, dir, actorFirst, actorLast, rmonth, genre);
	}
	else if (genre == "D")
	{
		setInitialMovie(istream, stock, dir, title);
		setComedyorDrama(istream, ryear);
		return new Drama(stock, ryear, title, dir, genre);
	}
	else if (genre == "F")
	{
		setInitialMovie(istream, stock, dir, title);
		setComedyorDrama(istream, ryear);
		return new Comedy(stock, ryear, title, dir, genre);
	}
	else// if (type == 'Z')	// allows the coverage of all other genre types that aren't correct
	{
		setInitialMovie(istream, stock, dir, title);
		setClassic(istream, actorFirst, actorLast, rmonth, ryear);
		return NULL;
	}
}

Movie* MediaFactory::createMovie(string type, int stock, string dir, string title, int ryear, string actorFirst, string actorLast, int rmonth)
{

	if (type == "C")
	{
		return new Classic(stock, ryear, title, dir, actorFirst, actorLast, rmonth, type);
	}
	else if (type == "D")
	{
		return new Drama(stock, ryear, title, dir, type);
	}
	else if (type == "F")
	{
		return new Comedy(stock, ryear, title, dir, type);
	}
	else// if (type == 'Z')	// allows the coverage of all other genre types that aren't correct
	{
		//setInitialMovie(istream, stock, dir, title);
		//setClassic(istream, actorFirst, actorLast, rmonth, ryear);
		return NULL;
	}
}

void MediaFactory::setInitialMovie(istream& istream, int& stock, string& dir, string& title)
{
	istream.ignore();
	istream >> stock;

	istream.ignore();
	getline(istream >> ws, dir, ',');
	istream.ignore();

	getline(istream >> ws, title, ',');
}

void MediaFactory::setClassic(istream& istream, string& actorFirst, string& actorLast, int& rmonth, int& ryear)
{
	istream >> actorFirst >> actorLast >> rmonth >> ryear;
}

void MediaFactory::setComedyorDrama(istream& istream, int& ryear)
{
	istream >> ryear;
}