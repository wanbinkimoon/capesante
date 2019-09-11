
//  Shapes.hpp
//  001
//
//  Created by nicola bertelloni on 06/04/2019.
//

#ifndef Shapes_hpp
#define Shapes_hpp

#include "ofMain.h"

class Shapes : public ofBaseApp {
public:
  void square();
  
  void squareHalf(bool reverse);
  
  void circle();
  void circleOfCircles();
  void dottedCircle();
  void circleHalf(bool reverse);
  
  void triangleSplit(bool reverse);
  
  
  
  int mw = ofGetHeight();
};



#endif /* Shapes_hpp */
