#include "stdafx.h"
#include "History.h"


History::History()
{
}


History::History(string id, CustomerRecords &custRec)
{
	Customer *custPtr = custRec.find(id);
	if (custPtr != NULL)
	{
		custPtr->printHistory();
	}
	else
	{
		cout << "Customer# " << id << " not found during History transaction" << endl;
	}
}

History::~History()
{
}
