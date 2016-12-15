//#include "stdafx.h"
#include "Movie.h"


Movie::Movie()
{
	stock = 0;
	year = 1900;
	title = "No Title";
	director = "No Director";
	genre = "No Genre";
}


Movie::Movie(int ct, string yr, string name, string dir, string gen)
{
	stock = ct;
	year = yr;
	title = name;
	director = dir;
	genre = gen;
}

Movie::Movie(const Movie& mov)
{
	*this = mov;
}

Movie::~Movie()
{
}

int Movie::getStock()
{
	return stock;
}

string Movie::getYear()
{
	return year;
}

string Movie::getTitle()
{
	return title;
}

string Movie::getDirector()
{
	return director;
}

string Movie::getGenre()
{
	return genre;
}

void Movie::setStock(int s)
{
	stock = s;
}

void Movie::setYear(string y)
{
	year = y;
}

void Movie::setTitle(string t)
{
	title = t;
}

void Movie::setDirector(string d)
{
	director = d;
}

void Movie::setGenre(string g)
{
	genre = g;
}

bool Movie::operator>(const Movie &mov)
{
	return (this->title > mov.title);
}

bool Movie::operator==(const Movie &mov)
{
	return ((this->stock == mov.stock) && (this->year == mov.year) && (this->title == mov.title) && (this->director == mov.director));
}

bool Movie::operator!=(const Movie &mov)
{
	return ((this->stock != mov.stock) || (this->year != mov.year) || (this->title != mov.title) || (this->director != mov.director));
}

bool Movie::decreaseStock()
{
	if (stock > 0)
	{
		stock--;
		return true;
	}
	else
	{
		cout << "Insufficient stock to check out: " << getTitle() << endl;
		return false;
	}
}

bool Movie::increaseStock()
{
	stock++;
	return true;
}

ostream& operator<<(ostream& output, const Movie &mov)
{
	output << "Title: " << mov.title << " / Director: " << mov.director << ", Year: " << mov.year << ", Stock: " << mov.stock << endl;
	return output; 
}