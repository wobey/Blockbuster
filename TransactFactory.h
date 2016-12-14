#include "Transaction.h"
#include "Borrow.h"
#include "History.h"
#include "Inventory.h"
#include "Return.h"

#pragma once
class TransactFactory
{
public:
	static Transaction* makeTransaction(MediaLibrary &lib, CustomerRecords *custTable, char type, string custId, char media, char genre,
		string title, string dir, string actorFirst, string actorLast, int month, int yr);
};

