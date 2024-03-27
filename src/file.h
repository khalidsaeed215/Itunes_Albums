#pragma once
#include <stdlib.h>

#include <string.h>

#include<iostream>

#include <string>

#include <fstream>

#include "ofMain.h"

using namespace std;
#define N_MAX 1000
class Files {
private:
	string artists[N_MAX];
	string file[N_MAX];
	ofHttpResponse resp;
	int n;
public:
	string addPlus(string);


	void addToFileArray(string name);
	Files();
	//void writeToFile(string[]);






};