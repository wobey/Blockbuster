#include "stdafx.h"
#include "MediaLibrary.h"

MediaLibrary::MediaLibrary()
{
	classics = new BSTree<Classic>;
	dramas = new BSTree<Drama>;
	comedies = new BSTree<Comedy>;
}

Movie* MediaLibrary::search(string genre, string month, string yr, string title, string dir, string actorLast)
{
	Movie* findMovie;

	if (genre == "C")
	{
		findMovie = classics->retrieve(yr, actorLast);
	}
	else if (genre == "D")
	{
		findMovie = dramas->retrieve(dir, title);
	}
	else
	{
		findMovie = comedies->retrieve(title, yr);
	}

	return findMovie;
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

void MediaLibrary::print()
{
	cout << "Movie Library: " << endl;
	cout << "Classics" << endl;
	classics->print();
	cout << "" << endl;
	cout << "Dramas" << endl;
	dramas->print();
	cout << "" << endl;
	cout << "Comedies" << endl;
	comedies->print();
	cout << "" << endl;
}

MediaLibrary::~MediaLibrary()
{	
	//Deletes any movies remaining in the genre BSTrees
	classics->makeEmpty();
	dramas->makeEmpty();
	comedies->makeEmpty();

	// TODO verify with valgrind there are no leaks here
}



