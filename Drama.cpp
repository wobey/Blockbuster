#include "stdafx.h"
#include "Drama.h"


Drama::Drama(int ct, string yr, string name, string dir): Movie(ct, yr, name, dir)
{
} //end Drama()

Drama::Drama(const Drama &drm)
{
	*this = drm;
}

ostream& operator<<(ostream& output, Drama &drm)
{
	output << "Title: " << drm.getTitle() << " / Director: " << drm.getDirector() << ", Year: " << drm.getYear() 
		<< ", Stock: " << drm.getStock() << "Genre: Drama" << endl;
	return output;
}

Drama::~Drama()
{
}
