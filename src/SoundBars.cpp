//
//  SoundBars.cpp
//  001
//
//  Created by nicola bertelloni on 06/04/2019.
//

#include "SoundBars.hpp"

void SoundBars::draw(vector<float> melBands){
  ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
  ofFill();
  ofSetColor(100, 255, 50);

  float bin_h = (float) ofGetHeight() / melBands.size() * 2;
  
  for (int i = 0; i < melBands.size(); i++){
    if(melBands[i] > .35) {
      ofDrawRectangle(0, bin_h * 2 * i , ofGetWidth(), (bin_h * .2) * (melBands[i] + 1));
    }
  }
  ofDisableBlendMode();
}

