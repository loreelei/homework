#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetFrameRate(60);
    ballpos = glm::vec2(ofRandom(0,200),200);
    ballvel = glm::vec2(ofRandom(2,5),2);
//
    glm::vec2 pos = glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5);     // center screen
    ParticleSystem particleSystem = ParticleSystem(pos);

//    particleSystems.push_back(particleSystem);
    
    // setup general gravity force
    
    gravity = glm::vec2(0, .15);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].applyForce(gravity);
        particleSystems[i].update();
    }
    if ( ballpos.x>= ofGetWidth()) {
        ballpos.x = ofGetWidth();
        ballvel.x*=-1;
        particleSystems.push_back(ParticleSystem(glm::vec2(ballpos.x,ballpos.y)) );
    }
    // check right
    else if (ballpos.x<= 0) {
        ballpos.x = 0;
        ballvel.x*=-1;
        particleSystems.push_back(ParticleSystem(glm::vec2(ballpos.x,ballpos.y)) );
    }
    // check top and bottom
    if ( ballpos.y>= ofGetHeight()) {
        ballpos.y = ofGetHeight();
        ballvel.y*=-1;
        particleSystems.push_back(ParticleSystem(glm::vec2(ballpos.x,ballpos.y)) );
    }
    // check right
    else if (ballpos.y<= 0) {
        ballpos.y = 0;
        ballvel.y*=-1;
        particleSystems.push_back(ParticleSystem(glm::vec2(ballpos.x,ballpos.y)) );
    }
    if(ofGetMousePressed()){
        ballpos+=ballvel*2;
    }
    ballpos+=ballvel;
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString("try click the mouse", 20, 20);
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].draw();
    }
    ofDrawCircle(ballpos, 20);
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // create a new particle system at mouse position on click
    
    particleSystems.push_back( ParticleSystem(glm::vec2(x,y)) );
    
}
