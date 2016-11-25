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
//#include "HashTable.h"
#include "BSTree.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
using namespace std;

class MediaLibrary
{
public:
	MediaLibrary();								// default constructor
	MediaLibrary(const MediaLibrary&);
	~MediaLibrary();							// destructor

	MediaLibrary& operator=(const MediaLibrary&);
	bool operator==(const MediaLibrary&);
	bool operator!=(const MediaLibrary&);

	bool insert(const Movie&);
	bool remove(const Movie&);
	Movie* find(const Movie&) const;
	Movie* retrieve(const string&) const;
	bool isEmpty() const;
	int size() const;
	void clear();

private:
	//HashTable<BSTree<>>		// TODO: how to create a generic hash table of generic bstress (that store different data types)
	BSTree<Comedy> comedies;
	BSTree<Drama> dramas;
	BSTree<Classic> classics;
};
#endif