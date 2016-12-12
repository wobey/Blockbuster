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
int Customer::hash() const
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

//---------------------------- operator << -------------------------------------
// displays customer information
ostream& operator<<(ostream& ostream, const Customer& rhs)
{
	ostream << "Cusomer Name: " << rhs.getFirstName() << " " << rhs.getLastName() << " ";
	ostream << "ID: " << rhs.getID() << endl;

	// TODO: output customers rental history

	return ostream;
}