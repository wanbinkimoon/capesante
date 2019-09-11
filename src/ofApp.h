#pragma once

#include "ofMain.h"
#include "ofxAudioAnalyzer.h"
#include "Shapes.hpp"
#include "SoundBars.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void audioIn();
    void exit();
    void audioIn(ofSoundBuffer &inBuffer);

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
  
    Shapes shape;
    float thresholdVal;
  
    SoundBars bars;
  
    bool drawBars = false;
  
    float smooth;
    float rms_l, rms_r;
    vector<float> melBands;
    ofxAudioAnalyzer audioAnalyzer;
    ofSoundStream soundStream;
};
