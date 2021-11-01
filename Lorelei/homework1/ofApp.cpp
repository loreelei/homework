#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    ballnumber=0;
    clicktime = 0;
    currentMode = SPRING;
}

//--------------------------------------------------------------
void ofApp::update(){
     
    for (int a=0; a<=ballnumber; a++){
        ball[a].setMode(currentMode);
        ball[a].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i=0; i<=clicktime; i++){
        ball[i].draw();
        ballnumber++;
    }
    ofDrawBitmapString(currentModeStr + "\n\nClick 's'to play. \nKeys 1-4 to change mode.", 10, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == '1'){
        currentMode = SPRING;
        currentModeStr = "Spring";
    }
    if( key == '2'){
        currentMode = SUMMER;
        currentModeStr = "Summer";
    }
    if( key == '3'){
        currentMode = AUTUMN;
        currentModeStr = "Autumn";
    }
    if( key == '4'){
        currentMode = WINTER;
        currentModeStr = "Winter";
    }
    if( key == 's' ){
        clicktime++;
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
