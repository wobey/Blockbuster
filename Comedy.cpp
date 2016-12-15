//#include "stdafx.h"
#include "Comedy.h"



Comedy::Comedy(int ct, int yr, string name, string dir, string gen): Movie(ct, yr, name, dir, gen)
{
} //end Comedy

Comedy::Comedy(const Comedy &com)
{
	*this = com;
} //end Comedy

Comedy::~Comedy() { }

bool Comedy::compareGreater(Comedy* rhs)
{
	// will check titles first if they exist
	if (title.compare(rhs->title) != 0)
		return title.compare(rhs->title) > 0;

	// if not title, compare years
	return year > rhs->year;
}

bool Comedy::compareEqual(Comedy* rhs)
{
	// determines if the titles and years are identical
	if (title.compare(rhs->title) == 0 && year == rhs->year)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& output, Comedy& drm)
{
	output << "Title: " << drm.getTitle() << " / Director: " << drm.getDirector() << ", Year: " << drm.getYear()
		<< ", Stock: " << drm.getStock() << "Genre: Comedy" << endl;

	return output;
} //end operator<<