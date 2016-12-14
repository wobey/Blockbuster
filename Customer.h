#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <iostream>

#include "MediaLibrary.h"
#include "Movie.h"
//#include "TransactionHistory.h"

using namespace std;

class Customer
{
	friend ostream& operator<<(ostream& output, const Customer cust);

public:
	Customer();
	Customer(string custID, string last, string first);
	~Customer();

	//Getters
	string getID() const;
	string getFirstName() const;
	string getLastName() const;

	//Overloads
	Customer operator=(const Customer&);

	//Other
	static int hash(string) ;
	bool insertRental(string media, string genre, string title,
		string dir, string actorFirst, string actorLast, string month, string yr);
	Movie* searchRentals(string, string, string, string, string, string);
	bool deleteRental(Movie*);

private:
	//data
	string id;
	string lastName;
	string firstName;
	MediaLibrary rentals;
	//TransactionHistory history;

};
#endif //CUSTOMER_H_INCLUDED
