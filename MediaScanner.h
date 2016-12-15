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
#include "MediaLibrary.h"
#include "MediaFactory.h"
using namespace std;

class MediaScanner
{
public:
	MediaScanner() {}					// default constructor
	MediaScanner(fstream&);			// constructor
	~MediaScanner();					// destructor

	MediaLibrary* getMediaLibrary();

private:
	MediaLibrary* media;

	void readFile(fstream&);
};
#endif