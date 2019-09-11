#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  int sampleRate = 44100;
  int bufferSize = 512;
  int outChannels = 0;
  int inChannels = 2;
  // setup the sound stream
  soundStream.setup(this, outChannels, inChannels, sampleRate, bufferSize, 3);
  
  //setup ofxAudioAnalyzer with the SAME PARAMETERS
  audioAnalyzer.setup(sampleRate, bufferSize, inChannels);
  
  smooth = .5;
  thresholdVal = .3;
}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer &inBuffer){
  //ANALYZE SOUNDBUFFER:
  audioAnalyzer.analyze(inBuffer);
}

//--------------------------------------------------------------
void ofApp::update(){
  rms_l = audioAnalyzer.getValue(RMS, 0, smooth);
  rms_r = audioAnalyzer.getValue(RMS, 1, smooth);
  melBands = audioAnalyzer.getValues(MEL_BANDS, 0, .2); // return an array of 24 bands

  for (int i = 0; i < melBands.size(); i++){
    melBands[i] = ofMap(melBands[i], DB_MIN, DB_MAX * 1.8, 0.0, 1.0, true);
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0);
  
  
  if (melBands[1] > thresholdVal) shape.squareHalf(false);
  if (melBands[2] > thresholdVal) shape.squareHalf(true);
  
  if (melBands[3] > thresholdVal) shape.circle();
  if (melBands[4] > thresholdVal) shape.circleOfCircles();
//  if (melBands[5] > thresholdVal) shape.dottedCircle();
  
//  if (melBands[6] > thresholdVal) shape.triangleSplit(false);
//  if (melBands[7] > thresholdVal) shape.triangleSplit(true);
  
  if (melBands[6] > thresholdVal) shape.circleHalf(true);
  if (melBands[7] > thresholdVal) shape.circleHalf(false);
  
//  ofEnableBlendMode(OF_BLENDMODE_ADD);
  if (melBands[0] > thresholdVal) shape.square();
//  ofEnableBlendMode(OF_BLENDMODE_DISABLED);
  
  if (drawBars) bars.draw(melBands);
  
}

//--------------------------------------------------------------
void ofApp::exit(){
  ofSoundStreamStop();
  audioAnalyzer.exit();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if(key == '0'){
    drawBars = !drawBars;
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
  
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
