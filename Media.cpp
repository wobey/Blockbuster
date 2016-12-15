//#include "stdafx.h"
#include "Media.h"


Media::Media()
{
}

Media::Media(const Media &med)
{
}


Media::~Media()
{
}

Media Media::operator=(const Media &)
{
	return Media();
}

Media Media::operator+(const Media &mov)
{
	return *this;
}

bool Media::operator>(const Media &med)
{
	return false;
}

bool Media::operator==(const Media &med)
{
	return false;
}

bool Media::operator!=(const Media &)
{
	return false;
}

ostream& operator<<(ostream& output, const Media med)
{
	output << "Media" << endl;
	return output;
}