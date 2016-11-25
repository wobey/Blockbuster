// ------------------------------------------------ MovieFactory.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H
#include <iostream>
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
using namespace std;

class MovieFactory
{
public:
	MovieFactory();							// default constructor
	~MovieFactory();						// destructor

	static Movie* CreateMovie(string&);
};
#endif