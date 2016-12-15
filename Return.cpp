//#include "stdafx.h"
#include "Return.h"


Return::Return(MediaLibrary & lib, CustomerRecords *custTable, string custId, string media, string genre, string title, string dir,
	string actorFirst, string actorLast, string month, string yr)
{
	doTransaction(lib, custTable, custId, media, genre, title, dir, actorFirst, actorLast, month, yr);
}

Return::~Return()
{
}

void Return::doTransaction(MediaLibrary &lib, CustomerRecords *custTable, string custId, string media, string genre, string title,
	string dir, string actorFirst, string actorLast, string month, string yr)
{
	//Search for customer
	Customer *custPtr = custTable->find(custId);
	if (custPtr != NULL)
	{
		//Find movie in customer library
		Movie* moviePtr = custPtr->searchRentals(genre, month, yr, title, dir, actorLast);

		if (moviePtr != NULL)
		{
			//Delete from customer's rentals
			custPtr->deleteRental(moviePtr);
			custPtr->addHistory("Return", title, dir, actorFirst, actorLast, month, yr);

			//Add movie back to library stock
			Movie *findMovie = lib.search(genre, month, yr, title, dir, actorLast);

			if (findMovie != NULL) 
			{
				findMovie->increaseStock();
			}
		}
		else
		{
			cout << "Movie was not found during Return transation: " << title << endl;
		}
	}
	else
	{
		cout << "Customer ID " << custId << " was not found during Return transaction." << endl;
	}
}
