//#include "stdafx.h"
#include "MediaScanner.h"

MediaScanner::MediaScanner(fstream& fstream)
{
	media = new MediaLibrary();
	readFile(fstream);
}

MediaScanner::~MediaScanner() 
{ 
	// TODO: ensure this is the correct way
	//delete media;
	media->~MediaLibrary();
}

void MediaScanner::readFile(fstream& fstream)
{
	while (fstream.peek() != EOF)//!fstream.eof())
	{
		Movie* movie = MediaFactory::createMovie(fstream);

		if (movie != NULL)
		{
			media->insert(movie, movie->getGenre());
		}
		else
			delete movie;
	}

	fstream.close();

	//cout << *media->classics << endl;
	//cout << *media.comedies << endl;
	//cout << *media.dramas << endl;
}

MediaLibrary* MediaScanner::getMediaLibrary()
{
	return media;
}