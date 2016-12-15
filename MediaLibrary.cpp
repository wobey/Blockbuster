//#include "stdafx.h"
#include "MediaLibrary.h"

MediaLibrary::MediaLibrary()
{
	classics = new BSTree<Classic>;
	dramas = new BSTree<Drama>;
	comedies = new BSTree<Comedy>;
}

Movie* MediaLibrary::search(string genre, int month, int yr, string title, string dir, string first, string last)
{
	Movie* findMovie = NULL;

	if (genre == "C")
	{
		Classic* classic = new Classic;
		classic->setYear(yr);
		classic->setActorFirst(first);
		classic->setActorLast(last);
		findMovie = classics->retrieve(classic);
		delete classic;
	}
	else if (genre == "D")
	{
		Drama* drama = new Drama;
		drama->setDirector(dir);
		drama->setTitle(title);
		findMovie = dramas->retrieve(drama);
		delete drama;
	}
	else if (genre == "F")
	{
		Comedy* comedy = new Comedy;
		comedy->setTitle(title);
		comedy->setYear(yr);
		findMovie = comedies->retrieve(comedy);
		delete comedy;
	}

	else
		return NULL;

	return findMovie;
}

//bool MediaLibrary::insert(string media, string genre, string title, string dir, string actorFirst, string actorLast, string month, string yr)
//{
//	if (genre == "D")
//	{
//		Drama dMovie(1, yr, title, dir, genre);
//		dramas->insert(&dMovie, dir, title);
//	}
//	else if (genre == "F")
//	{
//		Comedy *cPtr = new Comedy(1, yr, title, dir, genre);
//		comedies->insert(cPtr, title, yr);
//	}
//	else
//	{
//		Classic *cPtr = new Classic(1, yr, title, dir, actorFirst, actorLast, month, genre);
//		classics->insert(cPtr, yr, actorLast);
//	}
//	
//	return true;
//}

bool MediaLibrary::insert(Movie* movie, string genre)
{
	if (genre == "D")
	{
		Drama* drama = dynamic_cast<Drama*>(movie);
		dramas->insert(drama, drama->getDirector(), drama->getTitle());
	}
	else if (genre == "F")
	{
		Comedy* comedy = dynamic_cast<Comedy*>(movie);
		comedies->insert(comedy, comedy->getTitle(), comedy->getYear());
	}
	else
	{
		Classic* classic = dynamic_cast<Classic*>(movie);
		classics->insert(classic, classic->getYear(), classic->getActorLast());
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
	//if (classics != NULL || dramas != NULL || comedies != NULL)
	//{
	//	classics->makeEmpty();
	//	dramas->makeEmpty();
	//	comedies->makeEmpty();
	//}

	//delete classics;
	//delete dramas;
	//delete comedies;

	// TODO verify with valgrind there are no leaks here
}

template <class T1>
ostream& operator<<(ostream& ostream, const BSTree<T1> rhs)
{
	ostream << *rhs;

	return ostream;
}