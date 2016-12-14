#include <iostream>
#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"

using namespace std;

class MediaFactory
{
public:
	static Movie *createMovie(string type, int stock, string dir, string title, string year, string actorFirst, string actorLast, string rmonth);
};