//#include "stdafx.h"
#include "Comedy.h"



Comedy::Comedy(int ct, string yr, string name, string dir): Movie(ct, yr, name, dir)
{
} //end Comedy

Comedy::Comedy(const Comedy &com)
{
	*this = com;
} //end Comedy

Comedy::~Comedy() { }

bool Comedy::compareGreater(const Comedy* rhs) const
{
	// will check titles first if they exist
	if (title.compare(rhs->title) != 0)
		return title.compare(rhs->title) > 0;

	// if not title, compare years
	return std::stoi(year) > std::stoi(rhs->year);
}

bool Comedy::compareEqual(const Comedy* rhs) const
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