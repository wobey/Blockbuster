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
public:
	MediaLibrary();								// default constructor
	~MediaLibrary();							// destructor

	Movie* search(int, int, string, string);

private:

	BSTree<Comedy> *comedies;
	BSTree<Drama> *dramas;
	BSTree<Classic> *classics;
};
#endif