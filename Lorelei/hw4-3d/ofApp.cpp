#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    ofBackground(70, 120, 120);
    
    ofSetSmoothLighting(true);
    ofSetFrameRate(60);
    
    for (int i=0;i<=100;i++)
    {
        a[i].x=ofRandom(-6000,6000);
        a[i].y=-200;
        a[i].z=ofRandom(-6000,6000);
        radius[i] = ofRandom(100,200);
      
    }
  
    
    // create the ground
    ground.set(10000, 10000, 1000, 1000);       // really big
    ground.rotateDeg(-90, glm::vec3(1,0,0));    // turn horizontal
    ground.move(0, -200, 0);                    // move down
    
    // gravity
    gravity = ofVec3f(0,-.003,0);
    
    
//    firelight.setPointLight();
//    firelight.setPosition(0,400,0);
    sunlight.setDirectional();
    sunlight.setPosition(100,100,-400);
    sunlight.lookAt(glm::vec3(0));
    sunlight.setDiffuseColor( ofColor::white);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // spawn new eruption particles
   
    
    while (eruption.size() > 5000)
    {
        eruption.erase(eruption.begin());
    }
    
    for (int i=0; i<eruption.size(); i++)
    {
        eruption[i].applyForce(gravity);
        eruption[i].update();
    }
    

    // use noise to animate the fire brightness
    float noise = ofNoise(ofGetElapsedTimef() * 2.);
    float hue   = noise * 20.;
    float brt   = noise * 255.;
//    firelight.setDiffuseColor( ofColor::fromHsb(hue, 255, brt));

    // animate sun rotation
//    sunlight.rotateDeg(.2, 0,1,0);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
   
    ofBackgroundGradient( ofColor(0,0.,0),ofColor::midnightBlue,OF_GRADIENT_LINEAR);
    
    ofEnableLighting();
    
    cam.begin();
    ofEnableDepthTest();
    
//    firelight.enable();
    
    for (int i=0; i<eruption.size(); i++)
    {
        eruption[i].draw();
    }
    
    sunlight.enable();
    
    for (int i=0; i<=300; i++){

        ofSetColor(102,51,0);
    
        ofDrawCylinder(a[i], 60,250);
        ofSetColor(0,150,0);
        ofDrawCone(a[i].x, 30, a[i].z, 150, -230);
        ofDrawCone(a[i].x, 170, a[i].z, 70, -140);
//        ofSetColor(102,51,0);
//
//        ofDrawCylinder(a[i], radius[i],radius[i]*2);
//        ofSetColor(139,39,9);
//        ofDrawCone(a[i].x, a[i].y+radius[i]*2, a[i].z, radius[i]*3/2, -330);
    }
    
   
//    volcano.drawAxes(100);
    
    ofSetColor( ofColor::springGreen) ;//ofColor(70,120,10));
    ground.draw();
    ofSetColor(255);
    
    firelight.disable();
    sunlight.disable();
    ofDisableLighting();
    
    ofDisableDepthTest();
    
    // you can draw the lights on top of your scene
     firelight.draw();
     sunlight.draw();
    
    
    cam.end();

    ofDrawBitmapStringHighlight("Try press space key", ofVec2f(20,20));

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if ( key == ' '){
        glm::vec3 pos(ofRandom(-2000,2000),ofRandom(300,500),ofRandom(-2000,2000));
    for (int i=0; i<50; i++)
    {
        Particle p;
        p.pos = pos;
        p.vel.x = ofRandom(-1,1);
        p.vel.y = ofRandom(-1,1);    // up
        p.vel.z = ofRandom(-1,1);
        p.lifespan = ofRandom(7,9);
        p.mass = ofRandom(.7,1.3);
        eruption.push_back(p);
       
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
