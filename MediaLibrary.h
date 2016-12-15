// ------------------------------------------------ MediaLibrary.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef MEDIALIBRARY_H
#define MEDIALIBRARY_H
#include <iostream>
#include "BSTree.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
using namespace std;

class MediaLibrary
{
	template <class T1>
	friend ostream& operator<<(ostream&, const BSTree<T1>&);

public:
	MediaLibrary();								// default constructor
	~MediaLibrary();							// destructor

	Movie* search(string, string, string, string, string, string);
	bool insert(string media, string genre, string title, string dir, string actorFirst, string actorLast, string month, string yr);
	bool insert(Movie*, string);
	bool deleteMovie(Movie* ptr);
	void print();

public:
	BSTree<Comedy> *comedies;
	BSTree<Drama> *dramas;
	BSTree<Classic> *classics;
};
#endif