//#include "stdafx.h"
#include "Borrow.h"

Borrow::Borrow(MediaLibrary &lib, CustomerRecords *custTable, string custId, string media, string genre, string title, string dir,
	string actorFirst, string actorLast, string month, string yr)
{
	doTransaction(lib, custTable, custId, media, genre, title, dir, actorFirst, actorLast, month, yr);
}

Borrow::~Borrow()
{
}

void Borrow::doTransaction(MediaLibrary &lib, CustomerRecords *custTable, string custId, string media, string genre, string title,
	string dir, string actorFirst, string actorLast, string month, string yr)
{

	//Search for the movie in stock
	//If the movie exists in the library, lookup customer
	Movie *findMovie = lib.search(genre, month, yr, title, dir, actorLast);
	if (findMovie != NULL)
		{
			//Find the customer checking out the movie
			//If the customer exists and movie is in stock
			//Aadjust customer inventory and library stock
			Customer *custPtr = custTable->find(custId);
			if (custPtr != NULL)
			{
				bool hasStock = findMovie->decreaseStock();
				if (hasStock)
				{
					custPtr->insertRental(media, genre, title, dir, actorFirst, actorLast, month, yr);
					custPtr->addHistory("Borrow ", title, dir, actorFirst, actorLast, month, yr);
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
