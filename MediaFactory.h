#include <iostream>
#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"

using namespace std;

class MediaFactory
{
public:
	static Movie *createMovie(char type, int stock, string dir, string title, int year, string actorFirst, string actorLast, int rmonth);
};