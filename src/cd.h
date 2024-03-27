#pragma once
#include <stdlib.h>

#include <string.h>

#include<iostream>

#include <string>

#include <fstream>

#include "ofMain.h"
#include <vector>

using namespace std;

#define N_MAX 1000

class CD {
public:
	vector <string> artists;
	int numArtists;
	//string fanName;
	//CD cd1[N_MAX];
	string artist;
	void setFromCSV1(string csv);
	int parse(string csv, string values[]);
	int getCommaIndex(string str, int index[]);

	vector <string> year;

	vector <string> albumTitle;
	
	vector <string> imageUrl;
	int numImageUrl;
	int numYear;
	int numTitle;
	void print(string label, int n);
	int setFromCSV(string csv, string find,int num);
	void setImageUrl(int n, string values[]);
	void setArtists(int n, string values[]);
	void setYear(int n, string values[]);
	void setAlbumTitle(int n, string values[]);
	int isDuplicate(int n, string [], string []);
	int getIndex(string str, int index[], string title);
	int parseCSV(string csv, string [], string find);

	




};