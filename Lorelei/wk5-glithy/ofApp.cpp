#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myPlayer.load("dance.mov");
    myPlayer.play();
}

//--------------------------------------------------------------
void ofApp::update(){
//  kinect.update();
    myPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  for (int i = 0; i < myPlayer.getWidth(); i+= 16) {
    for (int j = 0; j < myPlayer.getHeight(); j+= 16) {
      ofColor color1 = myPlayer.getPixels().getColor(i, j);
     
     
      float brightness = color1.getBrightness();
      float radius = ofMap(brightness, 0, 255, 0, 8);
        ofSetColor(color1);
        if (ofGetMousePressed()){
            ofSetColor(brightness);
        }
      ofDrawRectangle(i, j, radius,radius);
    }
  }
   ofDrawBitmapString("Try press the mouse", 50, 50);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//  kinect.setCameraTiltAngle(0);
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
