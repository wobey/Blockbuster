#include "stdafx.h"
#include "Drama.h"


Drama::Drama(int ct, string yr, string name, string dir): Movie(ct, yr, name, dir)
{
} //end Drama()

Drama::~Drama() { }


Drama::Drama(const Drama &drm)
{
	*this = drm;
}

bool Drama::compareGreater(const Drama* rhs) const
{
	// compare directors, titles, and year
	if (director.compare(rhs->director) != 0)
		return director.compare(rhs->director) > 0;

	else if (title.compare(rhs->title) != 0)
		return title.compare(rhs->title) > 0;

	return std::stoi(year) > std::stoi(rhs->year);
}

bool Drama::compareEqual(const Drama* rhs) const
{
	// determines if the titles and years are identical
	if (director.compare(rhs->director) == 0 && title.compare(rhs->title) == 0)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& output, Drama &drm)
{
	output << "Title: " << drm.getTitle() << " / Director: " << drm.getDirector() << ", Year: " << drm.getYear() 
		<< ", Stock: " << drm.getStock() << "Genre: Drama" << endl;
	return output;
}

