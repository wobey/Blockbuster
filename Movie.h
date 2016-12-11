#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Movie
{
	friend ostream& operator<<(ostream& output, const Movie &mov);

public:
	//constructors
	Movie();
	Movie(int ct, int yr, string name, string dir);
	Movie(const Movie&);
	virtual ~Movie();

	//getters and setters
	int getStock();
	int getYear();
	string getTitle();
	string getDirector();

	void setStock(int);
	void setYear(int);
	void setTitle(string);
	void setDirector(string);

	//assigns
	virtual Movie operator=(const Movie &mov);

	//operator overloads
	virtual bool operator>(const Movie&);
	virtual bool operator==(const Movie&);
	virtual bool operator!=(const Movie&);

private:
	//data
	int stock;
	int year;
	string title;
	string director;

};
#endif // MOVIE_H_INCLUDED
