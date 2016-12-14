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
		Drama dMovie(1, yr, title, dir);
		dramas->insert(&dMovie);
	}
	else if (genre == 'F')
	{
		Comedy *cPtr = new Comedy(1, yr, title, dir);
		comedies->insert(cPtr);
	}
	else
	{
		Classic *cPtr = new Classic(1, yr, title, dir, actorFirst, actorLast, month);
		classics->insert(cPtr);
	}
	
	return true;
}

bool MediaLibrary::deleteMovie(Movie *ptr)
{
	
}

MediaLibrary::~MediaLibrary()
{
	//Deletes any movies remaining in the genre BSTrees
	classics->makeEmpty();
	dramas->makeEmpty();
	comedies->makeEmpty();

}



