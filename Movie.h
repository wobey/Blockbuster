// ------------------------------------------------ Movie.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>
using namespace std;

class Movie
{
public:
	Movie();							// default constructor
	~Movie() { cout << "~Movie()"; }
	Movie(int&, int&, string&, string&, string&);
	Movie(const Movie&);				// copy constructor

	Movie& operator=(const Movie&);
	bool operator==(const Movie&) const;
	bool operator!=(const Movie&) const;

private:
	int stock;
	int year;
	string title;
	string director;
	string genre;						// C, D, or F
};
#endif