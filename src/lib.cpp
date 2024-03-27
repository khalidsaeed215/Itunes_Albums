
#include "lib.h"


Cdlib::Cdlib(){
n=1;

}
/*
void Cdlib::getTitles(string titles[]) {

	for (int i = 0; i < n; i++)
	{

		titles[i] = cds[i].title;

	}



}
void Cdlib::getArtist(string artist[]) {

	for (int i = 0; i < n; i++)
	{

		artist[i] = cds[i].artist;

	}


}
void Cdlib::getYear(int year[]) {

	for (int i = 0; i < n; i++)
	{

		year[i] = cds[i].year;

	}


}
void Cdlib::getGenre(string genre[]) {

	for (int i = 0; i < n; i++)
	{

		genre[i] = cds[i].genre;

	}


}
void Cdlib::getFan(string fan[]) {

	for (int i = 0; i < n; i++)
	{

		fan[i] = cds[i].fan;

	}


}*/
void Cdlib::swap(int *a, int *b)
{

	int n;
	n = *a;
	*a = *b;
	*b = n;

}

void Cdlib::swap(string *a, string *b)
{

	string n;
	n = *a;
	*a = *b;
	*b = n;

}
void Cdlib::sortVectorStringsByIndex(int dim, vector <string> x, int index[])
{
	string *x_temp;// , *index;

	x_temp = new string[dim];
	//index = new int[n];

	for (int i = 0; i < dim; i++)
	{
		x_temp[i] = x[i];
		index[i] = i;
		//cout << index[i];
	}
	for (int j = 0; j < dim; j++)
	{
		for (int i = 1; i < dim; i++)
		{
			if (x_temp[i - 1] > x_temp[i])
			{
				//cout << endl;
				swap(&x_temp[i - 1], &x_temp[i]);
				swap(&index[i - 1], &index[i]);

			}
		}

	}
}
/*void Cdlib::sortStringsByIndex(int dim, string x[], int index[])
{
	string *x_temp;// , *index;

	x_temp = new string[dim];
	//index = new int[n];

	for (int i = 0; i < dim; i++)
	{
		x_temp[i] = x[i];
		index[i] = i;
		//cout << index[i];
	}
	for (int j = 0; j < dim; j++)
	{
		for (int i = 1; i < dim; i++)
		{
			if (x_temp[i - 1] > x_temp[i])
			{
				//cout << endl;
				swap(&x_temp[i - 1], &x_temp[i]);
				swap(&index[i - 1], &index[i]);

			}
		}

	}
}*/

void Cdlib::sortByIndex(int dim, int x[], int index[])
{
	int *x_temp;// , *index;

	x_temp = new int[dim];
	//index = new int[n];

	for (int i = 0; i < dim; i++)
	{

		x_temp[i] = x[i];
		index[i] = i;
		//cout << index[i];

	}
	for (int j = 0; j < dim; j++)
	{
		for (int i = 1; i < dim; i++)
		{
			if (x_temp[i - 1] > x_temp[i])
			{
				//cout << endl;
				swap(&x_temp[i - 1], &x_temp[i]);
				swap(&index[i - 1], &index[i]);

			}
		}

	}
}
string Cdlib::addPlus(string name)
{

	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] == ' ')
			name[i] = '+';
	}

	return name;
}

void Cdlib::setFromFile(string name) {
	
	
	string name1 = addPlus(name);
	cds.artist = name;
	resp = ofLoadURL("https://itunes.apple.com/search?term=" + name1);
	int numWords;

	cds.numTitle=cds.setFromCSV(resp.data, "\"collectionName\":\"", 0);
	cds.numImageUrl=cds.setFromCSV(resp.data, "\"artworkUrl100\":\"", 2);
	cds.numYear =cds.setFromCSV(resp.data, "\"releaseDate\":\"", 1);

	//n++;
	//unCopiedVal = r;

}

/*void Cdlib::printByIndex(int dim, int index[], string label, int d) {
	cout << "\n\n" << label << ": ";
	string p;

	for (int i = 0; i < n; i++)
	{
		p = "[" + to_string(i) + "]";
		cds[index[i]].print(p);
	}
}*/

void Cdlib::print(string label,int n1) {

	cout << "\n\n" << label << ": ";
	string p;
	//for (int i = 0; i < n1; i++)
	//{
		p = "[" + to_string(n) + "]";
		cds.print(p,n1);
	//}
}

void Cdlib::addToFav(int spot) {
	//fav = fopen("Favorites.txt", "r");
	int numWords;
	//cout << "in";
	string line;
	ifstream myFile("Favorite.txt");
	string arr[10000];
	int t;
	
	t=read(arr);
/*	if (myFile.is_open() == true)
	{
		while (getline(myFile, line))
		{
			//cout << line[i] << "\n";
			
				arr[t] = line;
				
				//cout << line;
			t++;
			cout <<"t:"<< t<<endl;
			//'cout << "hi"<<line;
		}
		myFile.close();
	}*/
	
/*	for (int i = 0; i < t; i++)
	{
		cout << arr[i]<<endl;
		//cout << "hello";
	}*/
	ofstream writeFile("Favorite.txt");
	//writeFile.open();

	//= fopen("Favorites.txt", "w");
	for (int i = 0; i < t; i++)
	{
		writeFile << arr[i]+"\n";
		cout << arr[i] << endl;
	}

	writeFile << cds.artist<<",";
	if (spot < cds.numTitle)
		writeFile << cds.albumTitle[spot] << ",";
	else
		writeFile << cds.albumTitle[0] << ',';
	if (spot <= cds.numYear)
		writeFile << cds.year[spot]<<",";
	writeFile << cds.imageUrl[spot]<<endl;
	

	
	writeFile.close();
}

void Cdlib::clearFavList() {
	ofstream writeFile("Favorite.txt");
	writeFile.clear();
	writeFile.close();
}

void Cdlib::setFromFavFile() {
	int numWords;
	
	//cout << "in";
	
	string line;
	
	string fileName = "Favorite.txt";

	ifstream myFile(fileName.c_str());

	//n = 0;
	
	if (myFile.is_open() == true)
	{
		while (getline(myFile, line))
		{
			//cout << line[i] << "\n";

			cds.setFromCSV1(line);
			//n++;
			//'cout << "hi"<<line;
		}
		myFile.close();
	}
}
int Cdlib::read(string out[])
{

	int numWords;
	//cout << "in";
	string line;
	ifstream myFile("Favorite.txt");


	numWords = 0;
	if (myFile.is_open() == true)
	{
		while (getline(myFile, line))
		{
			//cout << line << "\n";
			out[numWords] = line;
			numWords++;
		}
		myFile.close();
	}
	return numWords;


}

void Cdlib::sortFav(int dim, vector<string> fav, int index[])
{
	string *x_temp;// , *index;

	x_temp = new string[dim];
	//index = new int[n];

	for (int i = 0; i < dim; i++)
	{
		x_temp[i] = fav[i];
		index[i] = i;
		cout << "C: "<<index[i]<<endl;
	}
	for (int j = 0; j < dim; j++)
	{
		for (int i = 1; i < dim; i++)
		{
			if (x_temp[i - 1] > x_temp[i])
			{
				//cout << endl;
				swap(&x_temp[i - 1], &x_temp[i]);
				swap(&index[i - 1], &index[i]);

			}
		}

	}
	for (int i = 0; i < dim; i++)
	{
		cout << "This: " << index[i] << endl;
	}



}