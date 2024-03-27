#include "cd.h"


int CD::getIndex(string str, int index[], string title) {
	int i, n, count;
	n = str.length();
	count = 0;
	int pos = 0;
	for (i = 0; i < n; i++)
	{
		if (i == str.find(title,pos))
		{
			index[count] = i-1;
			count = count + 1;
			pos = i + 1;
		}
		
		//cout << endl;
	}
	//cout << endl << count;;
	return count;
}

int CD::parseCSV(string csvstr,string values[], string find)
{
	int i1, i2, len;
	int cIndex[7000];
	int count = 0;
	int numLocations = getIndex(csvstr, cIndex, find);
	int val = find.length();
	string trees[1000];
	int numValues = numLocations + 1;
	int mark[1000];

	for (int i = 0; i < numLocations; i++)
		mark[i] = cIndex[i] + val;


	for (int i = 0; i < numValues; i++)
	{
		//cout << endl<<i;
		int j = mark[i]+1;
		
		while (j < csvstr.length())
		{
			if (csvstr[j] == '"')
			{
				len = j - mark[i]-1;
				trees[i] = csvstr.substr(mark[i] + 1, len);
				
				count = count + 1;
				//cout << endl << "broken"<<j;
				//cout << endl << len;
				//cout << endl << mark[i];
				break;

			}
				j++;
		}
		cout << endl << trees[i];
		//cout << i;
	} 
	if (find == "\"releaseDate\":\"")
	{
		for (int i = 0; i < numValues; i++)
		{
			trees[i] = trees[i].substr(0, 10);
			cout << endl << trees[i];
		}
	}
	int tree = isDuplicate(numValues, trees, values);
	cout << tree << endl;
	cout << numValues << endl;
	for (int i = 0; i < tree; i++)
	{
		cout << values[i]<<endl;
	}

	return (tree);
}

int CD::isDuplicate(int n,string s[],string out[])
{
	string temp;
	bool isDuplicate;


	int val = 0;
	for (int i = 1; i < n; i++)
	{
		temp = s[i - 1];
		isDuplicate = false;
		for (int j = 1; j < n; j++)
		{
			if(temp==out[j])
				isDuplicate = true;
		}
		if (!isDuplicate)
		{
			out[val]=s[i-1];
			val++;
		}
	}
	return val;

}

void CD::setImageUrl(int n1,string values[])
{

	//imageurl[0] = values[0];
	for (int i = 0; i < n1; i++)
		imageUrl.push_back(values[i]);

}
void CD::setYear(int n, string values[])
{

	//imageurl[0] = values[0];
	for (int i = 0; i < n; i++)
		year.push_back(values[i]);

}/*
void CD::setArtists(int n, string values[])
{

	//imageurl[0] = values[0];
	for (int i = 0; i < n; i++)
		artist.push_back(values[i]);

}*/

void CD::setAlbumTitle(int n, string values[])
{

	//imageurl[0] = values[0];
	for (int i = 0; i < n; i++)
		albumTitle.push_back(values[i]);

}

int CD::setFromCSV(string csv,string find,int num) {

	string values[100];
	int numValues;

	numValues = parseCSV(csv, values,find);
	cout << endl << endl << numValues;
	if (num == 0)
	{
		setAlbumTitle(numValues, values);
	}
	else if (num == 2)
	{
		setImageUrl(numValues, values);
	}
	else if (num == 1)
	{
		setYear(numValues, values);
	}

	return numValues;
	






}


void CD::print(string label, int n) {
	cout << endl << label;
	int t=albumTitle.size();

	cout << endl << "[" << 0 << "]: " << artist;

	cout << endl << "[" << 1 << "]: " ;
	for (int i = 0; i < numTitle; i++)
		cout << endl << albumTitle[i];

	cout << endl << "[" << 2 << "]: ";
	for (int i = 0; i < numYear; i++)
		cout << endl << year[i];
	cout << endl << "[" << 3 << "]: ";
	for (int i = 0; i < numImageUrl; i++)
		cout << endl << imageUrl[i];
	//cout << endl << "[" << 4 << "]: " << fan;
	//cout << endl << "[" << 5 << "]: " << imageUrl << endl;


}
void CD::setFromCSV1(string csv) {

	string values[4];
	int numValues;

	numValues = parse(csv, values);

	cout << values[0];
	cout << values[1];
	cout << values[2];
	cout << values[3];
	artists.push_back(values[0]);
	albumTitle.push_back(values[1]);
	year.push_back(values[2]);
	imageUrl.push_back(values[3]);
	numTitle++;
	numImageUrl++;
	numYear++;
	numArtists++;
	//genre = values[3];
	//fan = values[4];
	//imageUrl = values[5];

}
int CD::parse(string csvstr, string values[])
{
	
	int i1, i2, len;
	int cIndex[7000];

	int numCommas = getCommaIndex(csvstr, cIndex);
	cout << numCommas;
	int numValues = numCommas + 1;

	for (int i = 0; i < numValues; i++)
	{
		if (i == 0)i1 = 0;
		else i1 = cIndex[i - 1] + 1;

		if (i == numCommas)i2 = strlen(csvstr.c_str());
		else i2 = cIndex[i] - 1;

		len = i2 - i1 + 1;

		values[i] = csvstr.substr(i1, len);
	}

	return (numValues);
}

int CD::getCommaIndex(string str, int index[]) {
	int i, n, count;
	n = str.length();

	count = 0;
	for (i = 0; i < n; i++)
	{
		if (str[i] == ',')
		{
			index[count] = i;
			count = count + 1;
		}
	}
	return count;
}