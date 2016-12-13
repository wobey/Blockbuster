#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <iostream>

#include "MediaLibrary.h"
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
	int hash() const;
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
