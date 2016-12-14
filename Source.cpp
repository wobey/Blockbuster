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
//#include "HashTable.h"
//#include "Customer.h"
//#include "BSTree.h"
//#include "Classic.h"
//#include "Comedy.h"
//#include "Drama.h"

#include "Scanners.h"
using namespace std;

void readFiles();

int main()
{
	// ******************************************************
	//				  ACTUAL SUBMISSION
	// ******************************************************
	readFiles();


	// ******************************************************
	//					 BSTREE TEST
	// ******************************************************

	//BSTree<Classic> classics;
	//BSTree<Comedy> comedies;
	//BSTree<Drama> dramas;
	//Classic* classic;
	//Comedy* comedy;

	//fstream infile1("data4movies.txt");
	//if (!infile1) {
	//	cout << "File could not be opened." << endl;
	//	return 1;
	//}

	//int stock, ryear, rmonth;
	//string line, type, title, dir, actorFirst, actorLast;
	//Drama* drama1;
	//Drama* drama2;
	//Drama* drama3;

	//drama1 = new Drama(10, 1995, "Bob's Burgers", "Pete and Pete");
	//drama2 = new Drama(8, 2001, "Hand", "Das Boot");
	//drama3 = new Drama(7, 1921, "Cup", "Vertical");

	//dramas.insert(drama1, "Pete and Pete", "Bob's Burgers");
	//dramas.insert(drama2, "Das Boot", "Hand");
	//dramas.insert(drama3, "Vertical", "Cup");

	//cout << dramas << endl;

	//while (getline(infile1, line, ','))
	//{
	//	infile1 >> type;

	//	cout << type << endl;

	//	if (type != "" && (type == "C" || type == "D" || type == "F"))
	//	{
			//if (type == "C,")
			//{
			//	classic = new Classic(stock, ryear, title, dir, actorFirst, actorLast, rmonth);
			//	classics.insert(classic);
			//}
			//else if (type == "D,")
			//{
			//	drama = new Drama(stock, ryear, title, dir);
			//	dramas.insert(drama);
			//}
			//else if (type == "F,")
			//{
			//	comedy = new Comedy(stock, ryear, title, dir);
			//	comedies.insert(comedy);
			//}
	//	}
	//}
	//infile1.close();


	// ******************************************************
	//					HASH TABLE TEST
	// ******************************************************

	//HashTable<Customer> customers;

	//fstream infile2("data4customers.txt");
	//if (!infile2) {
	//	cout << "File could not be opened." << endl;
	//	return 1;
	//}

	//Customer* customer;

	//while (!infile2.eof())
	//{
	//	string id, last, first;

	//	infile2 >> id >> last >> first;
	//	
	//	customer = new Customer(id, last, first);

	//	if (id != "")
	//		customers.insert(customer);
	//	else
	//		delete customer;
	//}
	//infile2.close();

	//cout << customers;
	//cout << endl;
	//cout << "#Entries:" << customers.getNumEntries();

	//cout << endl;
	//cout << "Exists: " << customers.entryExists("5000") << endl;
	//cout << "Exists: " << customers.entryExists("5001") << endl;

	//customer = customers.retrieve("5000");
	//cout << *customer << endl;
	
	return 0;
}

void readFiles()
{
	fstream infile1("data4customers.txt");
	if (!infile1) {
		cout << "data4customers.txt could not be opened." << endl;
	}

	fstream infile2("data4movies.txt");
	if (!infile2) {
		cout << "data4movies.txt could not be opened." << endl;
	}

	fstream infile3("data4commands.txt");
	if (!infile3) {
		cout << "data4commands.txt could not be opened." << endl;
	}

	Scanners fileInput = Scanners(infile1, infile2, infile3);
	
	//fileInput.readFiles(infile1, infile2, infile3);
}