//#include "stdafx.h"
#include "MediaFactory.h"

Movie* MediaFactory::createMovie(istream& istream)//string type, int stock, string dir, string title, string ryear, string actorFirst, string actorLast, string rmonth)
{
	char type;
	string dir, title, ryear, actorFirst, actorLast, rmonth, genre;     
	int stock;
	Movie* movie;

	istream >> type;
	genre = type;

	if (genre == "" || istream.fail())
		return NULL;
	
	setInitialMovie(istream, stock, dir, title);

	if (genre == "C")
	{
		setClassic(istream, actorFirst, actorLast, rmonth, ryear);
		return new Classic(stock, ryear, title, dir, actorFirst, actorLast, rmonth, genre);
	}
	else if (genre == "D")
	{
		setComedyorDrama(istream, ryear);
		return new Drama(stock, ryear, title, dir, genre);
	}
	else if (genre == "F")
	{
		setComedyorDrama(istream, ryear);
		return new Comedy(stock, ryear, title, dir, genre);
	}
	else
		return NULL;
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

void MediaFactory::setClassic(istream& istream, string& actorFirst, string& actorLast, string& rmonth, string& ryear)
{
	istream >> actorFirst >> actorLast >> rmonth >> ryear;
}

void MediaFactory::setComedyorDrama(istream& istream, string& ryear)
{
	istream >> ryear;
}