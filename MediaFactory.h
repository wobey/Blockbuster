#include <iostream>
#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"

using namespace std;

class MediaFactory
{
public:
	static Movie *createMovie(istream&);//string type, int stock, string dir, string title, string year, string actorFirst, string actorLast, string rmonth);
	static void setInitialMovie(istream&, int&, string&, string&);
	static void setClassic(istream&, string&, string&, string&, string&);
	static void setComedyorDrama(istream&, string&);
};