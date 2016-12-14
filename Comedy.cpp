#include "stdafx.h"
#include "Comedy.h"



Comedy::Comedy(int ct, string yr, string name, string dir): Movie(ct, yr, name, dir)
{
} //end Comedy

Comedy::Comedy(const Comedy &com)
{
	*this = com;
} //end Comedy

ostream& operator<<(ostream& output, Comedy &drm)
{
	output << "Title: " << drm.getTitle() << " / Director: " << drm.getDirector() << ", Year: " << drm.getYear()
		<< ", Stock: " << drm.getStock() << "Genre: Comedy" << endl;
	return output;
} //end operator<<

Comedy::~Comedy()
{
} //end ~Comedy
