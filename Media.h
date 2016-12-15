#ifndef MEDIA_H_INCLUDED
#define MEDIA_H_INCLUDED

#include <iostream>

using namespace std;

class Media
{
	friend ostream& operator<<(ostream& output, const Media med);

public:
	//constructors
	Media();
	Media(const Media&);
	virtual ~Media();

	//assigns
	virtual Media operator=(const Media&);
	virtual Media operator+(const Media&);

	//comparitors
	virtual bool operator>(const Media&);
	virtual bool operator==(const Media&);
	virtual bool operator!=(const Media&);

};
#endif //MEDIA_H_INCLUDED
