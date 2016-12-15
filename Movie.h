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
	Movie(int, string, string, string, string);
	Movie(const Movie&);
	virtual ~Movie();

	//getters and setters
	int getStock();
	string getYear();
	string getTitle();
	string getDirector();
	string getGenre();

	void setStock(int);
	void setYear(string);
	void setTitle(string);
	void setDirector(string);
	void setGenre(string);

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
	string genre;
};
#endif // MOVIE_H_INCLUDED
