// ------------------------------------------------ NodeData.cpp ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#include "NodeData.h"

//------------------- constructors/destructor  -------------------------------
// default
template <typename T>
NodeData<T>::NodeData() 
{ 
	//data = ""; 
}                         

// needed so strings are deleted properly
template <typename T>
NodeData<T>::~NodeData() { }            

// copy
template <typename T>
NodeData<T>::NodeData(const NodeData<T>& nd)
{ 
	data = nd.data; 
}  

// 
template <typename T>
NodeData<T>::NodeData(const T& s)
{ 
	data = s;
}

//------------------------- operator= ----------------------------------------
template <typename T>
NodeData<T>& NodeData<T>::operator=(const NodeData<T>& rhs)
{
	if (this != &rhs) {
		data = rhs.data;
	}
	return *this;
}

//------------------------- operator==,!= ------------------------------------
template <typename T>
bool NodeData<T>::operator==(const NodeData<T>& rhs) const
{
	return data == rhs.data;
}

template <typename T>
bool NodeData<T>::operator!=(const NodeData<T>& rhs) const
{
	return data != rhs.data;
}

//------------------------ operator<,>,<=,>= ---------------------------------
template <typename T>
bool NodeData<T>::operator<(const NodeData<T>& rhs) const
{
	return data < rhs.data;
}

template <typename T>
bool NodeData<T>::operator>(const NodeData<T>& rhs) const
{
	return data > rhs.data;
}

template <typename T>
bool NodeData<T>::operator<=(const NodeData<T>& rhs) const
{
	return data <= rhs.data;
}

template <typename T>
bool NodeData<T>::operator>=(const NodeData<T>& rhs) const
{
	return data >= rhs.data;
}

//------------------------------ setData -------------------------------------
// returns true if the data is set, false when bad data, i.e., is eof
template <typename T>
bool NodeData<T>::setData(istream& infile)
{
	getline(infile, data);
	return !infile.eof();       // eof function is true when eof char is read
}

/*
(a). Overload << to display the true using inorder traversal. The NodeData class is responsible for
displaying its own data.
*/
//-------------------------- operator<< --------------------------------------
template <typename T>
ostream& operator<<(ostream& output, const NodeData<T>& nd)
{
	output << nd.data;
	return output;
}