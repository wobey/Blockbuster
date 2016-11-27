// ------------------------------------------------ NodeData.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
#include "Customer.h"
#include "Movie.h"
using namespace std;

template <class T>
class NodeData 
{
	friend ostream & operator<<(ostream&, const NodeData<T>&);

public:
	NodeData<T>();							// default constructor, data is set to an empty string
	~NodeData<T>();
	NodeData<T>(const T&);					// data is set equal to parameter
	NodeData<T>(const NodeData<T>&);		// copy constructor
	NodeData<T>& operator=(const NodeData<T>&);

	// set class data from data file
	// returns true if the data is set, false when bad data, i.e., is eof
	bool setData(istream&);

	bool operator==(const NodeData<T>&) const;
	bool operator!=(const NodeData<T>&) const;
	bool operator<(const NodeData<T>&) const;
	bool operator>(const NodeData<T>&) const;
	bool operator<=(const NodeData<T>&) const;
	bool operator>=(const NodeData<T>&) const;

private:
	T data;
};
#endif