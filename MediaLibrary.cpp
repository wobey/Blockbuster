#include "stdafx.h"
#include "MediaLibrary.h"

MediaLibrary::MediaLibrary()
{
	classics = new BSTree<Classic>;
	dramas = new BSTree<Drama>;
	comedies = new BSTree<Comedy>;
}

Movie* MediaLibrary::search(string, string, string, string, string, string)
{
	Movie* findMovie;
	return NULL;
}

bool MediaLibrary::insert(string media, string genre, string title, string dir, string actorFirst, string actorLast, string month, string yr)
{
	if (genre == "D")
	{
		Drama dMovie(1, yr, title, dir);
		dramas->insert(&dMovie, dir, title);
	}
	else if (genre == "F")
	{
		Comedy *cPtr = new Comedy(1, yr, title, dir);
		comedies->insert(cPtr, title, yr);
	}
	else
	{
		Classic *cPtr = new Classic(1, yr, title, dir, actorFirst, actorLast, month);
		classics->insert(cPtr, yr, actorLast);
	}
	
	return true;
}

bool MediaLibrary::deleteMovie(Movie *ptr)
{
	delete ptr;
	ptr = NULL;
	return true;
}

MediaLibrary::~MediaLibrary()
{
	//Deletes any movies remaining in the genre BSTrees
	classics->makeEmpty();
	dramas->makeEmpty();
	comedies->makeEmpty();

}



