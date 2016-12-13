#include "stdafx.h"
#include "MediaFactory.h"

Movie* MediaFactory::createMovie(char type, int stock, string dir, string title, int ryear, string actorFirst, string actorLast, int rmonth)
{
	if (type == 'C')
		return new Classic(stock, ryear, title, dir, actorFirst, actorLast, rmonth);
	else if (type == 'D')
		return new Drama(stock, ryear, title, dir);
	else if (type == 'F')
		return new Comedy(stock, ryear, title, dir);
	else
		return NULL;
}
