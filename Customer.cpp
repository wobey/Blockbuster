//#include "stdafx.h"
// ------------------------------------------------ Customer.cpp ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 12-11-16
// Date of Last Modification: 12-11-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#include "Customer.h"
#include <sstream>

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

	rentals = new MediaLibrary;
	history = new TransactionHistory;
}

//---------------------------- DefaultDestructor -------------------------------------
// destructor
Customer::~Customer()
{
	delete rentals;
	delete history;
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

//Customer Customer::operator=(const Customer &cust)
//{
//	id = cust.id;
//	lastName = cust.lastName;
//	firstName = cust.firstName;
//	MediaLibrary rentals(cust.rentals);
//	return *this;
//}

bool Customer::insertRental(string media, string genre, string title, string dir, string actorFirst, string actorLast, int month, int yr)
{
	//Check if customer has a copy of this movie
	//If not, insert new movie
	//Otherwise increment stock in customer rentals
	Movie *findMovie = rentals->search(genre, month, yr, title, actorFirst, actorLast, dir);
	
	if (findMovie == NULL)
	{	
		// create movie to insert 

		//rentals->insert(media, genre, title, dir, actorFirst, actorLast, month, yr);
	}
	else
	{
		findMovie->increaseStock();
	}

	return true;
}

Movie *Customer::searchRentals(string genre, int month, int yr, string title, string dir, string actorFirst, string actorLast)
{	
	Movie *findMovie = rentals->search(genre, month, yr, title, actorFirst, actorLast, dir);

	return findMovie;
}

bool Customer::deleteRental(Movie *moviePtr)
{
	moviePtr->decreaseStock();
	if (moviePtr->getStock() == 0)
	{
		rentals->deleteMovie(moviePtr);
	}
	return false;
}

void Customer::printHistory()
{
	cout << "Transaction history for customer# " << getID() << ": " << endl;
	history->print();
}

void Customer::addHistory(string trans, string title, string dir, string actorFirst, string actorLast, int month, int yr)
{
	stringstream ss1;
	ss1 << month;
	string _month = ss1.str();

	stringstream ss2;
	ss2 << yr;
	string _year = ss2.str();

	string totalTransaction = trans + " " + title + " " + dir + " " + actorFirst + " " + actorLast + " " + _month + " " + _year;
	history->insert(totalTransaction);
	
}

//---------------------------- operator << -------------------------------------
// displays customer information
ostream& operator<<(ostream& ostream, Customer& rhs)
{
	ostream << "Customer Name: " << rhs.getFirstName() << " " << rhs.getLastName() << " ";
	ostream << "ID: " << rhs.getID() << endl;

	// TODO: output customers rental history

	return ostream;
}