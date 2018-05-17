#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
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
	
	ofMesh plane;
	ofShader shader;
    
    ofSoundPlayer sound;
    vector<string> soundFiles;
    float time = 0;
    
    float* spectrum;
    
    ofFbo fboA, fboB, *curr, *prev;
    
    bool refreshImage;
    
    int w;
    int h;
    
    float accumulatedVal;
    float accumulatedVal2;

};
