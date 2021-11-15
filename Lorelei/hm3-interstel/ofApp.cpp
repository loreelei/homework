#include "ofApp.h"

// we declare these values as "globals" - they are outside of any class
//--------------------------------------------------------------

const int nMovers        = 40;
//const int nAttractors    = 5;
// "const" means the values can never change (they are "hard-coded" here)


//--------------------------------------------------------------
// ofApp class definitions:
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetBackgroundAuto(false);         // don't clear the background each frame
    ofSetFrameRate(60.);                // limit frame rate to 60 frames per second

    // construct Movers and Attractors
    
    // movers
    for (int m=0; m<nMovers; m++)
    {
        movers.push_back(Mover());
    }
    
    // attractors
    glm::vec2 center = glm::vec2( ofGetWidth() *.5, ofGetHeight() * .5 );    // center screen
//    glm::vec2 mouse = glm::vec2(a,b);
//    glm::vec2 mouse1 = glm::vec2(ofGetMouseX(), ofGetMouseY());
////
    Attractor attractor = Attractor( );
    attractor.pos   = (center);
    attractors.push_back(attractor);
//

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // apply attractors' gravity forces on movers
    for (int a=0; a<attractors.size(); a++)
    {
        for (int m=0; m<nMovers; m++)
        {
            // calculate force
            glm::vec2 force = attractors[a].getForce(movers[m]);
            
            // apply force
            
            if (ofGetMousePressed()){
                movers[m].applyForce(force*5);
            }
            else {
                movers[m].applyForce(force);
            }
        }
    }
    
    // update movers
    for (int m=0; m<movers.size(); m++)
    {
        movers[m].update();
    }
    ofDrawBitmapString("Press to increase speed", 20, 50);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // manually draw a semi-transparent background
    
    ofSetColor(0, 0, 0, 20); // black with alpha for trails
    ofDrawRectangle(0,0, ofGetWidth(),ofGetHeight());
    
    // draw attractors and movers
    
    for (int a=0; a<attractors.size(); a++)
    {
        attractors[a].draw();
    }
    
    for (int m=0; m<nMovers; m++)
    {
        movers[m].draw();
    }
    ofSetColor(255, 255, 255);
    for (int n = 0; n<=40; n++){
        ofDrawCircle(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()),1);
    }

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
    a=x;
    b=y;
//    ofDrawCircle(a,b,100);
   mouse = glm::vec2(a,b);
//    glm::vec2 mouse1 = glm::vec2(ofGetMouseX(), ofGetMouseY());
//
//    attractor.pos   = (mouse);
//    attractors.push_back(Attractor(mouse));
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
