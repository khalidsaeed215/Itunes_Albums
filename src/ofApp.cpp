#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	turn = true;
	ofSetBackgroundColor(255, 255, 255);
	num = 0;
	//Cdlib lib;

	/*cout << "Please enter artists name: ";
	string lil;
	cin >> lil;
	Files f;
	f.addPlus(lil);
	string values[1000];
	ofHttpResponse resp = ofLoadURL("https://itunes.apple.com/search?term=" + lil);
	string arr[10];

	arr[0] = resp.data;
	cout << arr[0];

	CD c;
	 val=c.parseCSV(resp.data, values, "artworkUrl100\":\"");
	 for (int i = 0; i < val; i++)
	 {

	 }*/
	
	string arr[1000];
	int z=myLib.read(arr);
	for (int i = 0; i < 5; i++)
	{
		//cout << z << endl;
	//	cout << arr[i] << endl;
	}
	int x[100];
//	cout << "Please enter artists name: ";
	//cin >> lil;
	int n = 0;
	font.load("googlefont1.ttf", 50);
	font2.load("googlefont1.ttf", 25);
	font1.load("googlefont1.ttf", 15);
	font3.load("googlefont1.ttf", 7);
	//myLib.setFromFile(lil);
	//cout << myLib.unCopiedVal;
	//myLib.print("First guy", myLib.unCopiedVal);
	//cout << myLib[0].n;

	//myLib.sortVectorStringsByIndex(myLib.unCopiedVal, myLib.cds.albumTitle,x);
	for (int i = 0; i < myLib.cds.numImageUrl; i++)
		myImage[i].load(myLib.cds.imageUrl[i]);
		
	//cout << "HAdafas fadsf " << myLib.unCopiedVal;
	//for(int i=0;i<myLa;)
	state = 0;
	for (int i = 0; i < z; i++)
	{
		index[i]=i;
	}

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	
	if (state == 0)
	{
		ofSetBackgroundColor(0, 0, 0);
		ofSetColor(255, 255, 255);
		font.drawString("CD LIBRARY", 300, 100);
		font2.drawString("Press spacebar to show albums", 250, 200);
		font2.drawString("Press A to search an artist", 300, 300);
		font2.drawString("Press P to view favorites", 300, 400);
		/*font2.drawString("Press A to sort by artist", 300, 500);
		font2.drawString("Press	G  to sort by genre", 300, 600);
		font2.drawString("Press F to sort by Fan name", 300, 700);
		font2.drawString("Press O to display original sorting", 200, 800);
		font2.drawString("Press SpaceBar to take you to home screen", 200, 900);*/
	}
	if (state == 1)
	{
		ofSetBackgroundColor(0, 0, 0);
		ofSetColor(255, 255, 255);
		font.drawString("Favorites", 350, 100);
		font2.drawString("Press spacebar to show albums", 250, 200);
		font2.drawString("Press 'A' to sort by artists", 300, 300);
		font2.drawString("Press 'T' to sort by title", 300, 400);
		font2.drawString("Press 'Y' to sort by Year", 300, 500);
		ofSetColor(255, 255, 255);
		ofRectangle rect(100, 900, 100, 50);
		ofDrawRectRounded(rect, 10);
		ofSetColor(0, 0, 0);
		font1.drawString("BACK", 110, 925);
		/*font2.drawString("Press A to sort by artist", 300, 500);
		font2.drawString("Press	G  to sort by genre", 300, 600);
		font2.drawString("Press F to sort by Fan name", 300, 700);
		font2.drawString("Press O to display original sorting", 200, 800);
		font2.drawString("Press SpaceBar to take you to home screen", 200, 900);*/
	}
	if (state == 2)
	{
		ofSetBackgroundColor(255,255, 255);
		if (thing == 1) {
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					ofSetColor(255, 255, 255);
					if (i*6+j < myLib.cds.numImageUrl)
						myImage[index[(42 * num) + 6 * i + j]].draw(150 * j, 150 * i);

					ofSetColor(0, 0, 0);
					if (drawSort == 0) {
						if ((i * 6 + j) < myLib.cds.albumTitle.size())
							font3.drawString(myLib.cds.albumTitle[index[(42 * num) + (6 * i) + j]], 150 * j, 125 * (i + 1) + (25 * i));
					}
					else if (drawSort == 1) {
						if ((i * 6 + j) < myLib.cds.year.size())
							font3.drawString(myLib.cds.year[index[(42 * num) + (6 * i) + j]], 150 * j, 125 * (i + 1) + (25 * i));
					}
					else if (drawSort == 2) {
						if ((i * 6 + j) < myLib.cds.artists.size())
							font3.drawString(myLib.cds.artists[index[(42 * num) + (6 * i) + j]], 150 * j, 125 * (i + 1) + (25 * i));
					}
				}


			}

		}
		if (thing == 0)
		{
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					ofSetColor(255, 255, 255);
					if (i*j < myLib.cds.numImageUrl)
						myImage[(42 * num) + 6 * i + j].draw(150 * j, 150 * i);


				}


			}
		}
		
			
		
		ofSetColor(0, 0, 0);
		ofRectangle rect(100, 900, 100, 50);
		ofDrawRectRounded(rect,5);
		
		ofSetColor(255, 255, 255);
		font1.drawString("BACK", 110, 925);
		ofSetColor(255, 255, 255);
		if (turn == true) {
			ofSetColor(0, 0, 0);
			ofRectangle rect(800, 900, 100, 50);
			ofDrawRectRounded(rect, 5);
			ofSetColor(255, 255, 255);
			font1.drawString("Erase", 810, 925);
			ofSetColor(255, 255, 255);
		}
	}
	//myImage[0].draw(100, 100);
}

//-------------------------------------------------------------
void ofApp::keyPressed(int key) {

	if (key == ' ') {
		state = 2;
	
	}
	

	if (key == 'a'&&state==0)
	{
		myLib.cds.artists.clear();
		myLib.cds.imageUrl.clear();
		myLib.cds.year.clear();
		myLib.cds.albumTitle.clear();
		cout << endl << "Enter new artists"<<endl;
		cin >> lil;
		myLib.setFromFile(lil);
		cout << myLib.unCopiedVal;
		myLib.print("First guy", myLib.unCopiedVal);
		//cout << myLib[0].n;

		//myLib.sortVectorStringsByIndex(myLib.unCopiedVal, myLib.cds.albumTitle,x);
		for (int i = 0; i < 1000; i++)
			myImage[i].load( "0");
		for (int i = 0; i < myLib.cds.numImageUrl; i++)
			myImage[i].load(myLib.cds.imageUrl[i]);
		cout << myLib.cds.numImageUrl;
		state = 0;
		thing = 0;
	}
	if (key == OF_KEY_LEFT)
	{
		if (num > 0)
			num--;
	}
	if (key == OF_KEY_RIGHT)
	{
		if (num < ((int)(myLib.cds.numImageUrl/42))+1)
			num++;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

	
/*	if (key == 't')
	{
		state = 0;
		myLib.cds.imageUrl.clear();
		myLib.cds.year.clear();
		myLib.cds.albumTitle.clear();
		//cout << endl << "Enter new artists" << endl;
		//cin >> lil;
		myLib.setFromFavFile();
		//cout << myLib.unCopiedVal;
		myLib.print("First guy", myLib.unCopiedVal);
		//cout << myLib[0].n;
		for (int i = 0; i < 1000; i++)
			myImage[i].load("0");
		//myLib.sortVectorStringsByIndex(myLib.unCopiedVal, myLib.cds.albumTitle,x);
		for (int i = 0; i < myLib.cds.numImageUrl; i++)
			myImage[i].load(myLib.cds.imageUrl[i]);
		cout << myLib.cds.numImageUrl;
	}*/
	if (key == 'p')
	{
		state = 1;
		turn = true;
		//state = 0;
		myLib.cds.numImageUrl = 0;
		myLib.cds.numTitle = 0;
		myLib.cds.numYear = 0;
		myLib.cds.imageUrl.clear();
		myLib.cds.year.clear();
		myLib.cds.albumTitle.clear();
		//cout << endl << "Enter new artists" << endl;
		//cin >> lil;
		myLib.setFromFavFile();
		//cout << myLib.unCopiedVal;
		myLib.print("First guy", myLib.unCopiedVal);
		//cout << myLib[0].n;
		for (int i = 0; i < 1000; i++)
			myImage[i].load("0");
		//myLib.sortVectorStringsByIndex(myLib.unCopiedVal, myLib.cds.albumTitle,x);
		for (int i = 0; i < myLib.cds.numImageUrl; i++)
			myImage[i].load(myLib.cds.imageUrl[i]);
		cout << myLib.cds.numImageUrl;
		thing = 0;
	}
	if (key == 't')
	{
		myLib.sortFav(myLib.cds.numImageUrl, myLib.cds.albumTitle, index);
		for(int i=0;i<myLib.cds.numImageUrl;i++)
			cout << "That: " << index[i] << endl;
		thing = 1;
		drawSort = 0;
	}
	if (key == 'y')
	{
		myLib.sortFav(myLib.cds.numYear, myLib.cds.year, index);
		for (int i = 0; i < myLib.cds.numYear; i++)
			cout << "That: " << index[i] << endl;
		thing = 1;
		drawSort = 1;
	}
	if (key == 'a'&&state==1)
	{
		myLib.sortFav(myLib.cds.numArtists, myLib.cds.artists, index);
		for (int i = 0; i < myLib.cds.numArtists; i++)
			cout << "That: " << index[i] << endl;
		thing = 1;
		drawSort = 2;
	}
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	for (int r = 0; r < 6; r++)
	{
		for (int c = 0; c < 7; c++)
		{
			if ((c + (r * 6) ) < myLib.cds.numImageUrl&&r*c<myLib.cds.numTitle&&state==2)
			{
				if (x >= 150 * c&&x <= (150 * c + 100) && y >= 150 * r &&y <= 150 * r + 100)
				{
					//myLib.addTo
					ofSetBackgroundColor(rand() % 256, 255, 255);
					cout << r * c;
					myLib.addToFav((c+(r*6)));

				}
			}
		}
	}
	if (x >= 100 && x <= 200 && y >= 900 && y <= 950 &&state==2)
	{
		state = 0;
		turn = false;
	}
	
	if (x >= 100 && x <= 200 && y >= 900 && y <= 950 && state==1)
	{
		state = 0;
		turn = false;
	}
	else if (x >= 800 && x <= 900 && y >= 900 && y <= 950)
	{
		turn = false;
		myLib.clearFavList();
		state = 0;
		
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
