#include "stdafx.h"
#include "MediaLibrary.h"

MediaLibrary::MediaLibrary()
{
	classics = new BSTree<Classic>;
	dramas = new BSTree<Drama>;
	comedies = new BSTree<Comedy>;
}

Movie* MediaLibrary::search(char, int, int, string, string, string)
{
	return NULL;
}

bool MediaLibrary::insert(char media, char genre, string title, string dir, string actorFirst, string actorLast, int month, int yr)
{
	if (genre == 'D')
	{
		Drama *cPtr = new Drama(1, yr, title, dir);
		dramas->insert(cPtr, dir, title);
	}
	else if (genre == 'F')
	{
		Comedy *cPtr = new Comedy(1, yr, title, dir);
		comedies->insert(cPtr, title, std::to_string(yr));
	}
	else
	{
		Classic *cPtr = new Classic(1, yr, title, dir, actorFirst, actorLast, month);
		classics->insert(cPtr, std::to_string(yr), actorLast);		// TODO: update year to release date and actor to full name (a mashup of month and year?)
	}
	
	return true;
}

bool MediaLibrary::deleteMovie(Movie *ptr)
{
	return true;
}

MediaLibrary::~MediaLibrary()
{
	//Deletes any movies remaining in the genre BSTrees
	classics->makeEmpty();
	dramas->makeEmpty();
	comedies->makeEmpty();

}



