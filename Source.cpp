//--------------------------------- Source.cpp -----------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
//---------------------------------------------------------------------------
// Purpose: This code tests the basic functionality of the classes to perform
// a program that will initialize the contents of an inventory from a file 
// (data4movies.txt), the customer list from another file (data4customers.txt), 
// and then process an arbitrary sequence of commands from a third file 
// (data4commands.txt).
//---------------------------------------------------------------------------

#include <iostream>
//#include "HashTable.cpp"
#include "HashTable.h"
#include "Customer.h"
using namespace std;

int main()
{
	HashTable<Customer> customers;

	Customer* testCustomer1 = new Customer("22", "Fitzgerald", "John");
	Customer* testCustomer2 = new Customer("33", "Sutton", "Christine");
	Customer* testCustomer3 = new Customer("12", "Marley", "Bob");

	customers.insert(testCustomer1);
	customers.insert(testCustomer2);
	customers.insert(testCustomer3);

	cout << customers;

	return 0;
}