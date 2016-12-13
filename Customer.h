#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <iostream>
#include <fstream>

#include "MediaLibrary.h"
//#include "TransactionHistory.h"

using namespace std;

class Customer
{
	friend ostream& operator<<(ostream& ostream, const Customer rhs)
	{
		ostream << "Cusomer Name: " << rhs.getFirstName() << " " << rhs.getLastName() << " ";
		ostream << "ID: " << rhs.getID() << endl;

		// TODO: output customers rental history

		return ostream;
	}

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
	static int hash(string);
	bool insertRental(char media, char genre, string title,
		string dir, string actorFirst, string actorLast, int month, int yr);
	Movie* searchRentals(int, int, string, string, string);
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
