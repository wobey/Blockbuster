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
Customer::Customer(int idNum, string last, string first)
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