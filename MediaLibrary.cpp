#include "stdafx.h"
#include "MediaLibrary.h"

MediaLibrary::MediaLibrary()
{
	classics = new BSTree<Classic>;
	dramas = new BSTree<Drama>;
	comedies = new BSTree<Comedy>;
}

Movie* MediaLibrary::search(int, int, string, string)
{

	return nullptr;
}

MediaLibrary::~MediaLibrary()
{
	//TODO: delete dynamically allocated BSTrees
}


