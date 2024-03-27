#pragma once

#include "ofMain.h"
//#include "file.h"
#include "cd.h"
#include "lib.h"

using namespace std;

class ofApp : public ofBaseApp{

public:

	//CD sd;
	int thing;
	int drawSort;
		
		//Cdlib *myLib;
		Cdlib myLib;
		bool turn;
		int index[1000];
		string lil;
		int num;
		int state;
		ofTrueTypeFont font,font1,font2,font3;
		//Cdlib myLib[100];
		ofImage myImage[1000];
		int val;
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
