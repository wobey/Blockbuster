#include "stdafx.h"
#include "Movie.h"


Movie::Movie()
{
	stock = 0;
	year = 1900;
	title = "No Title";
	director = "No Director";
}


Movie::Movie(int ct, string yr, string name, string dir)
{
	stock = ct;
	year = yr;
	title = name;
	director = dir;
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

Movie Movie::operator=(const Movie &mov)
{
	//duplicate check
	if (this == &mov)
	{
		return *this;
	}

	stock = mov.stock;
	year = mov.year;
	title = mov.title;
	director = mov.director;

	return *this;
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