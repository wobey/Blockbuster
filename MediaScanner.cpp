//#include "stdafx.h"
#include "MediaScanner.h"

MediaScanner::MediaScanner(fstream& fstream)
{
	media = MediaLibrary();
	readFile(fstream);
}

MediaScanner::~MediaScanner() { }

void MediaScanner::readFile(fstream& fstream)
{
	while (!fstream.eof())
	{
		Movie* movie = MediaFactory::createMovie(fstream);

		if (movie != NULL)
		{
			media.insert(movie, movie->getGenre());
		}
		else
			delete movie;
	}

	fstream.close();

	cout << media.classics << endl;
	cout << media.comedies << endl;
	cout << media.dramas << endl;
}
