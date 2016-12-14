#include "stdafx.h"
#include "TransactFactory.h"

Transaction *TransactFactory::makeTransaction(MediaLibrary &lib, CustomerRecords *custTable, string type, string custId, string media, string genre,
	string title, string dir, string actorFirst, string actorLast, string month, string yr)
{
	if (type == "B")
		return new Borrow(lib, custTable, custId, media, genre, title, dir, actorFirst, actorLast, month, yr);
	/*else if (type == 'H')
		return new History();
	else if (type == 'I')
		return new Inventory(); */
	else if (type == "R")
		return new Return(lib, custTable, custId, media, genre, title, dir, actorFirst, actorLast, month, yr);
	else
		return NULL;
}
