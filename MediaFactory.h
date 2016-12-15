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
	static Movie *createMovie(string type, int stock, string dir, string title, int year, string actorFirst, string actorLast, int rmonth);
	static void setInitialMovie(istream&, int&, string&, string&);
	static void setClassic(istream&, string&, string&, int&, int&);
	static void setComedyorDrama(istream&, int&);
};