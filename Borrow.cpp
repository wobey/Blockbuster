//#include "stdafx.h"
#include "Borrow.h"

Borrow::Borrow(MediaLibrary &lib, CustomerRecords custTable, string custId, char media, char genre, string title, string dir,
	string actorFirst, string actorLast, int month, int yr)
{
	doTransaction(lib, custTable, custId, media, genre, title, dir, actorFirst, actorLast, month, yr);
}

Borrow::~Borrow()
{
}

void Borrow::doTransaction(MediaLibrary &lib, CustomerRecords custTable, string custId, char media, char genre, string title, 
	string dir, string actorFirst, string actorLast, int month, int yr)
{

	//Search for the movie in stock
	//If the movie exists in the library, lookup customer
	Movie *findMovie = lib.search(month, yr, title, dir, actorLast);
	if (findMovie != NULL)
		{
			//Find the customer checking out the movie
			//If the customer exists and movie is in stock
			//Aadjust customer inventory and library stock
			Customer *custPtr = custTable.find(custId);
			if (custPtr != NULL)
			{
				bool hasStock = findMovie->decreaseStock();
				if (hasStock)
				{
					custPtr->insertRental(media, genre, title, dir, actorFirst, actorLast, month, yr);
					//TODO: Transaction History
				}
				
			}
			else
			{
				cout << "Customer ID " << custId << " was not found during Borrow transaction." << endl;
			}

		}
	else
	{
		cout << "Movie was not found in library during Borrow transaction: " << title << endl;
	}
	
}
