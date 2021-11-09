#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(128,128,0);
//    ofSetFrameRate(5);
//    g= 182;
//    b= 193;
//    r=255;
//
//
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    

    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofBackground(ofRandom(200, 255), ofRandom(50, 100), ofRandom(120, 100));

    ofSetColor(0,0,0);
    ofDrawBitmapString("Try press/move the mouse", 10, 50);
    //---------------hair
    ofFill();
//        ofSetColor(210,180,140);
        ofBeginShape();
        ofVertex(ofGetWidth()/2-250,100);
        ofVertex(ofGetWidth()/2+250,100);
        ofVertex(ofGetWidth()/2+300,ofGetHeight());
        ofVertex(ofGetWidth()/2-300,ofGetHeight());
        ofEndShape(true);
    
//    mesh[1].draw();
   //--------------neck
    ofFill();
        ofSetColor(245,222,179);
        ofBeginShape();
        ofVertex(ofGetWidth()/2,ofGetHeight()/2+30);
        ofVertex(ofGetWidth()/2+50,ofGetHeight()/2);
        ofVertex(ofGetWidth()/2+50,ofGetHeight());
        ofVertex(ofGetWidth()/2,ofGetHeight());
        ofEndShape(true);
    
    //-------------face right
    ofFill();
       ofSetColor(245,222,179);
//    ofSetColor(ofRandom(210,245),ofRandom(180,222),ofRandom(140.179));
        ofBeginShape();
        ofVertex(ofGetWidth()/2-50,ofGetHeight()/2-100);
        ofVertex(ofGetWidth()/2+150,ofGetHeight()/2-100);
        ofVertex(ofGetWidth()/2+150,ofGetHeight()/2+200);
        ofVertex(ofGetWidth()/2-50,ofGetHeight()/2+250);
        ofEndShape(true);
    //-------------face left
    ofFill();
        ofSetColor(210,180,140);
//    ofSetColor(ofRandom(210,245),ofRandom(180,222),ofRandom(140.179));
        ofBeginShape();
        ofVertex(ofGetWidth()/2-50,ofGetHeight()/2-250);
        ofVertex(ofGetWidth()/2-200,ofGetHeight()/2-250);
        ofVertex(ofGetWidth()/2-200,ofGetHeight()/2+150);
        ofVertex(ofGetWidth()/2-50,ofGetHeight()/2+200);
        ofEndShape(true);
    //-------------eye right
    ofFill();
    ofSetColor(255,255,255);
    ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/2-25, 200, 70);
//    ofSetColor(0,0,0);
//    ofDrawEllipse(ofGetWidth()/2+100, ofGetHeight()/2,50,70);
    
    ball.draw();
    ball.update();
    
    //-------------eye left
    float distance = 35;
    float circlenumber = 6;
    int angle = 0;
    float x=ofGetWidth()/2-125;
    float y=ofGetHeight()/2-100;
    for (int i =0; i<=circlenumber; i++){
        float xOffset = cos(angle) * distance;
        float yOffset = sin(angle) * distance;
        ofSetColor(128,128,0);
        ofDrawCircle(x+xOffset,y+yOffset,30);
//        ofDrawLine(x11,y11,x11+xOffset,y11+yOffset);
        angle +=70;
    }
    ofSetColor(210,180,140);
    ofDrawCircle(ofGetWidth()/2-125,ofGetHeight()/2-100,30);
    
    //------------cheek right
    
//    ofSetColor(255,182,193);
    
    if (ofGetMousePressed()){
        ofSetColor(ofRandom(200, 255), ofRandom(180, 150), ofRandom(70, 100));
    }
    else{
        ofSetColor(255,182,193);
    }
    ofDrawCircle(ofGetWidth()/2+150,ofGetHeight()/2+100,50);
    ofDrawCircle(ofGetWidth()/2-200,ofGetHeight()/2+80,50);//left
    
    //------------lips
    ofFill();
        ofSetColor(250,128,114);
        ofBeginShape();
        ofVertex(ofGetWidth()/2-90,ofGetHeight()/2+90);
        ofVertex(ofGetWidth()/2-120,ofGetHeight()/2+130);
        ofVertex(ofGetWidth()/2+30,ofGetHeight()/2+130);
        ofVertex(ofGetWidth()/2,ofGetHeight()/2+90);
        ofEndShape(true); //up
    
    ofVec2f p1(ofGetWidth()/2-120,ofGetHeight()/2+130);
    ofVec2f p2(ofGetWidth()/2+30,ofGetHeight()/2+130);
    ofVec2f p3(ofGetWidth()/2-10,ofGetHeight()/2+150);
    ofVec2f p4(ofGetWidth()/2-80,ofGetHeight()/2+150);
    ofDrawTriangle(p1,p2,p3);
    
    ofSetColor(250,128,114);
//    ofSetColor(ofRandom(100), ofRandom(120, 230), ofRandom(100,150));
    ofBeginShape();
    ofVertex(p1);
    ofVertex(p2);
    ofVertex(p3);
    ofVertex(p4);
    ofEndShape(true);//lower
    
//    ofSetColor(0,0,0);
//    ofDrawLine(p1,p2);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

  
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
