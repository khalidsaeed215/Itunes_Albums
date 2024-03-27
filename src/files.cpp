#include "file.h"
#include <stdio.h>
#include <stdlib.h>

string Files::addPlus(string name)
{

	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] == ' ')
			name[i] = '+';
	}

	return name;
}

void Files::addToFileArray(string name)
{
	artists[n - 1] = name;
	string name1 = addPlus(name);
	resp = ofLoadURL("https://itunes.apple.com/search?term=" + name1);
	file[n - 1] = resp.data;
	n++;
}

Files::Files()
{
	n = 1;
}


