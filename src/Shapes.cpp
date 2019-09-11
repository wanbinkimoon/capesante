//
//  Shapes.cpp
//  001
//
//  Created by nicola bertelloni on 06/04/2019.
//

#include "Shapes.hpp"

void Shapes::square(){
  float centerX = ofGetWidth() * .5;
  float centerY = ofGetHeight() * .5;
  
  float side = mw * .9;
  float x = centerX - side * .5;
  float y = centerY - side * .5;
  
  ofBackground(0);
  ofSetColor(255);
  ofDrawRectangle(x, y, side, side);
  
  side *= .4;
  x = centerX - side * .5;
  y = centerY - side * .5;
  
  ofSetColor(0);
  ofDrawRectangle(x, y, side, side);
}


void Shapes::circle(){
  float centerX = ofGetWidth() * .5;
  float centerY = ofGetHeight() * .5;
  
  float radius = (mw * .5) * .95;
  float x = centerX;
  float y = centerY;
  
  ofBackground(255);
  ofSetColor(0);
  ofSetCircleResolution(100);
  ofDrawCircle(x, y, radius);
}


void Shapes::circleOfCircles(){
  float centerX = ofGetWidth() * .5;
  float centerY = ofGetHeight() * .5;
  
  float radius = (mw * .5) * .95;
  float x = centerX;
  float y = centerY;
  
  int circNumb = 32;
  ofBackground(0);
  ofSetColor(255);
  ofNoFill();
  ofSetLineWidth(4);
  ofSetCircleResolution(100);
  for(unsigned int i = 0; i < circNumb; i++) {
    float diff = (radius / circNumb) * i ;
    ofDrawCircle(x, y, radius - diff);
  }
  ofFill();
}

void Shapes::dottedCircle(){
  float centerX = ofGetWidth() * .5;
  float centerY = ofGetHeight() * .5;
  
  float radius = (mw * .5) * .95;
  float x = centerX;
  float y = centerY;
  
  int circNumb = 32;
  
  ofBackground(0);
  ofSetColor(255);
  ofSetCircleResolution(100);
  
  float step = 20;
  
  ofPushMatrix();
  ofTranslate(centerX, centerY);
  for(unsigned int i = 0; i < circNumb; i++) {
    ofRotateDeg(i * .0025 * ofGetFrameNum() * .75);
    float diff = (radius / circNumb) * i;
    for(unsigned int j = 0; j < 360; j += step){
      float a = ofDegToRad(j);
      float x = (radius - diff) * cos(a);
      float y = (radius - diff) * sin(a);
      ofDrawCircle(x, y, 4);
    }
  }
  ofPopMatrix();
}

void Shapes::squareHalf(bool reverse){
  float centerX = ofGetWidth() * .5;
  float centerY = ofGetHeight() * .5;
  
  float side = mw * .9;
  float x = centerX - side * .5;
  float y = centerY - side * .5;
  
  ofBackground(reverse ? 255 : 0);
  ofSetColor(reverse ? 0 : 255);
  ofDrawRectangle(0, centerY, ofGetWidth(), ofGetHeight() * .5);
  ofSetColor(reverse ? 0 : 255);
  ofDrawRectangle(x, y, side, side * .5);
  ofSetColor(reverse ? 255 : 0);
  ofDrawRectangle(x, y + (side * .5), side, side * .5);

  side *= .4;
  x = centerX - side * .5;
  y = centerY - side * .5;
  
  ofSetColor(reverse ? 255 : 0);
  ofDrawRectangle(x, y, side, side * .5);
  ofSetColor(reverse ? 0 : 255);
  ofDrawRectangle(x, y + (side * .5), side, side * .5);
}

void Shapes::triangleSplit(bool reverse){
//  ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
  ofBackground(reverse ? 255 : 0);
  ofSetColor(reverse ? 0 : 255);
  if(reverse) {
  ofDrawTriangle(ofGetWidth(), 0, ofGetWidth(), ofGetHeight(), 0, ofGetHeight());
  } else {
  ofDrawTriangle(0, 0, 0, ofGetHeight(), ofGetWidth(), ofGetHeight());
  }
//  ofEnableBlendMode(OF_BLENDMODE_DISABLED);
}

void Shapes::circleHalf(bool reverse){
  float centerX = ofGetWidth() * .5;
  float centerY = ofGetHeight() * .5;
  
  float radius = (mw * .5) * .95;
  
  ofBackground(reverse ? 255 : 0);
  
  ofSetColor(reverse ? 0 : 255);
  ofDrawCircle(centerX, centerY, radius);

  ofSetColor(reverse ? 0 : 255);
  ofDrawRectangle(0, ofGetHeight() * .5, ofGetWidth(), ofGetHeight() * .5);
  
  ofSetColor(reverse ? 255 : 0);

  ofPushMatrix();
  ofTranslate(centerX, centerY);
//  ofRotateDeg(180);

  ofBeginShape();
  for(unsigned int j = 0; j <= 180; j ++){
    float a = ofDegToRad(j);
    float x = radius * cos(a);
    float y = radius * sin(a);
    ofVertex(x, y);
  }

  ofEndShape(true);
  ofPopMatrix();
}
