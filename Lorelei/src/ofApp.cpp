#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    mySound.load("interstellar.mp3");
//    mySound.play();
    ofBackground(0);
    ofEnableDepthTest();
    maxParticles = 200;
    ofSetSphereResolution(4);

    a= glm::vec3(ofRandom(-300,300),ofRandom(-300,300),ofRandom(-300,300));
    int numParticle =100;
    for (int i=0; i<numParticle; i++){
        particle newParticle(a.x,a.y,a.z,hue);
        particles.push_back(newParticle);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    a= glm::vec3(ofRandom(-300,300),ofRandom(-300,300),ofRandom(-300,300));
    if (particles.size()>maxParticles){
        particles.erase(particles.begin());
    }
    int numParticle =10;
    for (int i=0; i<numParticle; i++){
        particle newParticle(a.x,a.y,a.z,hue);
        particles.push_back(newParticle);
    }

    for (int i=0; i<particles.size(); i++){
        particles[i].update();
    }
    
}

////--------------------------------------------------------------
void ofApp::draw(){
//    ofDrawBitmapString("try click the mouse", 20, 20);
    
    cam.begin();
    ofRotateDeg(180,0,0,1);
    light.enable();
    ofDrawAxis(500);
    for (int i=0; i<particles.size(); i++){
        particles[i].draw();
    }
   
//    ofDrawCircle(ballpos, 20);
    light.disable();
    cam.end();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
           case ' ':
            
//
//        x=ofRandom(-500,500);
//        y=ofRandom(-500,500);
//        z=ofRandom(-500,500);
        hue = ofRandom(255);
        int numParticle =500;
        for (int i=0; i<numParticle; i++){
            particle newParticle(a.x,a.y,a.z,hue);
            particles.push_back(newParticle);
        }
            break;

    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int _x, int _y, int button){

   
}
//-----------------------------------------------

particle::particle(int startX, int startY, int startZ, int hue){
    // this is the constructor routine, called when we make a new object of our particle class defined in the header
    
    position = glm::vec3(startX, startY,startZ);
    
    if(ofGetKeyPressed (key = 'm')){
        force = glm::vec3(ofRandom(-0.5,0.5),ofRandom(-0.5,0.5),ofRandom(-0.5,0.5));
        direction = glm::vec3( ofRandom( -2.0, 2.0),ofRandom(-2.0, 2.0),ofRandom(-2.0, 2.0) );
    }
    else if(ofGetKeyPressed (key = 'd')){
        force = glm::vec3(0,0,ofRandom(0,0.5));
        direction = glm::vec3(0,0,ofRandom(0, 2.0) );
    }
    else{
        force =glm::vec3(0,0,0);
        direction =glm::vec3(0,0,0);
    }
   
    size = ofRandom(30,45);
    color.setHsb(hue,  255,  255, 200);
}
//--------------------------------------------------------------

particle::~particle(){
    // destructor
}
//--------------------------------------------------------------

void particle::update(){
    // update the particle x,y position by incrementing each by the velocity vx and vy
    position += direction ;
    direction +=  force/size;
        if (size > 1){
            size -=0.07;
        }
        float brightness = color.getBrightness();
        float myHue = color.getHue();
    
        if (brightness >20){
           // color.setBrightness( brightness -=0.5 );
            color.setHue( myHue -=0.5 );
    
        }
    
}

//--------------------------------------------------------------

void particle::draw(){
  
    ofPopStyle();
    if(ofGetMousePressed()){
        ofNoFill();
    }
    if(ofGetMousePressed()==false){
        ofFill();
    }
    ofPushMatrix();
    ofSetColor(color);
    ofDrawBox(position.x,position.y, position.z, size);
    ofPopMatrix();
    
}


//}
