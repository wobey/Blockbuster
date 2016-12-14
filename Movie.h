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
	Movie(int ct, string yr, string name, string dir);
	Movie(const Movie&);
	virtual ~Movie();

	//getters and setters
	int getStock();
	string getYear();
	string getTitle();
	string getDirector();

	void setStock(int);
	void setYear(string);
	void setTitle(string);
	void setDirector(string);

	//assigns
	virtual Movie* operator=(const Movie*);

	//operator overloads
	virtual bool operator>(const Movie&);
	virtual bool operator==(const Movie&);
	virtual bool operator!=(const Movie&);

	//other
	virtual bool decreaseStock();
	virtual bool increaseStock();

protected:
	//data
	int stock;
	string year;
	string title;
	string director;
};
#endif // MOVIE_H_INCLUDED
