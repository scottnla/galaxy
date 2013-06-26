#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofBackground(0,0,0);
  ofEnableSmoothing();
  ofEnableAlphaBlending();
  ofSetFrameRate(30);

  centerX = 0.5*ofGetWidth();
  centerY = 0.5*ofGetHeight();
  maxRad = 0.5*ofGetWidth();
  rotationSpeed = 0.2 / 60;
  eRatio = 0.85;
  eTwist = 8.0/maxRad;
  for(int i = 0; i < numStars; i++) {
    angle[i] = ofRandom(0,TWO_PI);
    radius[i] = abs(randomGauss())*maxRad*0.6;
  }
}

//--------------------------------------------------------------
void testApp::update(){
  for(int i = 0; i < numStars; i++) {
    float rad = radius[i];
    angle[i] += rotationSpeed*(maxRad / rad);
    posX[i] = centerX + sin(rad*eTwist)*rad*sin(angle[i]) + cos(rad*eTwist)*eRatio*rad*cos(angle[i]);
    posY[i] = centerY + cos(rad*eTwist)*rad*sin(angle[i]) - sin(rad*eTwist)*eRatio*rad*cos(angle[i]);
  }
}

//--------------------------------------------------------------
void testApp::draw(){
  for(int i = 0; i < numStars; i++) {
    float color = 40000.0 / radius[i];
    ofSetColor(color, color, color*0.9, 32);
    ofFill();
    ofCircle(posX[i], posY[i], 2);
  }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
float testApp::gauss(float x){
  return exp(-x*x/2.0) / sqrt(2*PI);
}

//--------------------------------------------------------------
float testApp::gaussInt(float x){
  if(x < -8.0) {
    return 0.0;
  }
  else if (x> 8.0) {
    return 1.0;
  }
  else {
    float sum = 0.0;
    float term = x;
    float counter = 3;
    while(sum + term != sum) {
      sum = term + sum;
      term = term*x*x/counter;
      counter += 2;
    }
    return 0.5 + sum*gauss(x);
  }      
}

//--------------------------------------------------------------
float testApp::gaussErr(float x){
  return gaussInt(x)*2 - 1;
}

//--------------------------------------------------------------
float testApp::randomGauss(){
  float x = 0;
  float y = 0;
  float r,c;
  do {
    x = ofRandom(-1,1);
    y = ofRandom(-1,1);
    r = x*x + y*y;
  }
  while(r == 0 || r > 1);
  c = sqrt(-2.0 * log(r) / r);
  return x*c;
}

//--------------------------------------------------------------
float testApp::randomGaussInt(float lower, float upper, float multiplier){
  return ofClamp(randomGauss()*(upper-lower)*multiplier + (upper + lower)/2.0, lower, upper);
}

//--------------------------------------------------------------
float testApp::randomGaussAt(float lower, float upper, float multiplier){
  return randomGauss()*(upper-lower)*multiplier + (upper + lower)/2.0;
}
