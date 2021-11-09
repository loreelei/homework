#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    num =10;
    ofBackground(153,204,255);
    for (int i = 0; i<num; i++) {
        ball[i].setup(ofRandom(0.1,4));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    

    for (int a=0; a<=num; a++){
        
        
        float y = ofRandom(0.005,0.012);
        
        ofPoint wind(x, 0);
        ofPoint gravity(0, y);
        ofPoint fly(0, -z);
        
        ball[a].applyForce(wind);
        ball[a].applyForce(gravity);
        ball[a].applyForce(fly);
        
        ball[a].update();
        ball[a].checkEdges();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
//
    for (int i=0; i<=num; i++){
        ball[i].draw();
        
    }
    ofDrawBitmapString("Click 1-4 to choose different wind mode. \nKeys 's' to start/restart.", 10, 20);
   

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == '1'){
        x= ofRandom(0.001,0.003);
        z=0;
    }
    if( key == '2'){
        x= ofRandom(-0.005,-0.01);
        z=0;
    }
    if( key == '3'){
        x= 0;
        z=0;
        
    }
    if( key == '4'){
        z = ofRandom(0.005,0.012);
    }
    if (key== 's'){
        for (int i = 0; i<num; i++) {
            ball[i].setup(ofRandom(0.1,4));
        }
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
