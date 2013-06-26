#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
 public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
 protected:
  float centerX;
  float centerY;
  static const int numStars = 50000;
  int maxRad;
  float rotationSpeed;
  float eRatio;
  float eTwist;
  float angle[numStars];
  float radius[numStars];
  float posX[numStars];
  float posY[numStars];

  float gauss(float x);
  float gaussInt(float x);
  float gaussErr(float x);
  float randomGauss();
  float randomGaussInt(float lower, float upper, float multiplier);
  float randomGaussAt(float lower, float upper, float multiplier);
};
