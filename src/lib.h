#pragma once


#include<iostream>
#include <fstream>
//#include "files.h"
using namespace std;

#include "cd.h"

#include "ofMain.h"

#define NMAX 100

class Cdlib {
public:
	
	int n;
	int unCopiedVal;
	CD cds;
	FILE *fav;
	//string a[];
	//ofImage image[NMAX];
	void setFromFavFile( );
	ofHttpResponse resp;
	void getTitles(string titles[]);
	void getArtist(string artist[]);
	void getGenre(string titles[]);
	void getYear(int year[]);
	void getFan(string fan[]);
	void sortVectorStringsByIndex(int dim, vector <string> x, int index[]);
	void sortByIndex(int dim, int x[], int index[]);
	void setFromFile(string fileName);
	void printByIndex(int dim, int index[], string label);
	void print(string label,int n1);
	string addPlus(string name);
	void clearFavList();
	//int n;
	Cdlib();
	//CD cds;
	void sortStringsByIndex1(int dim, vector <string> x, int index[]);
	void addToFav(int i);
	int read(string arr[]);
	void sortFav(int dim, vector<string> fav, int index[]);
private:
	void swap(string *a, string *b);
	void swap(int *a, int *b);
	
};
