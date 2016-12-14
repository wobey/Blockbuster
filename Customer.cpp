#include "stdafx.h"
// ------------------------------------------------ Customer.cpp ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 12-11-16
// Date of Last Modification: 12-11-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#include "Customer.h"

//---------------------------- DefaultConstructor -------------------------------------
// creates an empty customer
Customer::Customer()
{ }


//---------------------------- Constructor -------------------------------------
// creates a customer
Customer::Customer(string idNum, string last, string first)
{
	id = idNum;
	lastName = last;
	firstName = first;
}

//---------------------------- DefaultDestructor -------------------------------------
// destructor
Customer::~Customer()
{
}

//---------------------------- hash -------------------------------------
// returns a hash based on each of the customer's id numbers
int Customer::hash(string id)
{
	string keyID = id;
	int hashValue = 0;

	for (int i = 0; i < keyID.size(); i++)
		hashValue += keyID[i];

	return hashValue;
}

//---------------------------- getFirstName -------------------------------------
// returns customers first name
string Customer::getFirstName() const
{
	return firstName;
}

//---------------------------- getLastName -------------------------------------
// returns customers last name
string Customer::getLastName() const
{
	return lastName;
}

//---------------------------- getID -------------------------------------
// returns customers ID number
string Customer::getID() const
{
	return id;
}

Customer Customer::operator=(const Customer &cust)
{
	id = cust.id;
	lastName = cust.lastName;
	firstName = cust.firstName;
	MediaLibrary rentals(cust.rentals);
	return *this;
}

bool Customer::insertRental(string media, string genre, string title, string dir, string actorFirst, string actorLast, string month, string yr)
{
	//Check if customer has a copy of this movie
	//If not, insert new movie
	//Otherwise increment stock in customer rentals
	Movie *findMovie = rentals.search(genre, month, yr, title, actorLast, dir);
	
	if (findMovie == NULL)
	{	
		rentals.insert(media, genre, title, dir, actorFirst, actorLast, month, yr);
	}
	else
	{
		findMovie->increaseStock();
	}

	return true;
}

Movie *Customer::searchRentals(string genre, string month, string yr, string title, string dir, string actorLast)
{	
	Movie *findMovie = rentals.search(genre, month, yr, title, actorLast, dir);
	return findMovie;
}

bool Customer::deleteRental(Movie *moviePtr)
{
	moviePtr->decreaseStock();
	if (moviePtr->getStock() == 0)
	{
		rentals.deleteMovie(moviePtr);
	}
	return false;
}

//---------------------------- operator << -------------------------------------
// displays customer information
ostream& operator<<(ostream& ostream, const Customer& rhs)
{
	ostream << "Customer Name: " << rhs.getFirstName() << " " << rhs.getLastName() << " ";
	ostream << "ID: " << rhs.getID() << endl;

	// TODO: output customers rental history

	return ostream;
}