#include "stdafx.h"
#include "MediaScanner.h"

MediaScanner::MediaScanner(ifstream& ifstream)
{
	media = MediaLibrary();
	readFile(ifstream);
}

MediaScanner::~MediaScanner() { }

void MediaScanner::readFile(ifstream& ifstream)
{
	// implement code to read stream
}
