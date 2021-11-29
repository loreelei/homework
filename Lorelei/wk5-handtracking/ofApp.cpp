#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  webcam.setup(320,240);
    color.allocate(webcam.getWidth(), webcam.getHeight());
    gray.allocate(webcam.getWidth(), webcam.getHeight());
    background.allocate(webcam.getWidth(), webcam.getHeight());
    difference.allocate(webcam.getWidth(), webcam.getHeight());

}

//--------------------------------------------------------------
void ofApp::update(){
  webcam.update();
    if (webcam.isFrameNew()){
      color.setFromPixels(webcam.getPixels());
      gray = color;
      
      if (learn){
        background = gray;
        learn = false;
      }
      
      difference.absDiff(background, gray);
      difference.threshold(threshold);
      
      contour.findContours(difference, 50, webcam.getWidth() * webcam.getHeight(), 10, true);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
  webcam.draw(0,0,550,420);
//    gray.draw(100,0,100,100);
//    background.draw(0,0,550,420);
    difference.draw(550,0,550,420);
    ofFill();
    ofSetColor(mycolor);
    ofDrawRectangle(0,420,240,150);

//    color.draw(0, 0);
    contour.draw(0,0,550,420);
    
    ofDrawBitmapString("press on the image to substract color", 300, 600);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    mycolor = webcam.getPixels().getColor(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mycolor = webcam.getPixels().getColor(x, y);
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
