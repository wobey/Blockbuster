// ------------------------------------------------ MediaScanner.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef MEDIASCANNER_H
#define MEDIASCANNER_H
#include <iostream>
#include <list>
#include <fstream>
#include "Scanner.h"
#include "MediaLibrary.h"
using namespace std;

class MediaScanner : public Scanner<MediaLibrary>
{
public:
	MediaScanner(MediaLibrary&);			// default constructor
	~MediaScanner();						// destructor

private:
	MediaLibrary* library;

	void readFile(list<Movie>&, ifstream&);		// TODO: pass in a list???
};
#endif