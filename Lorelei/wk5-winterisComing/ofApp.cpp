
#include "ofApp.h"
//ofVec3f a(100,10,100);

//--------------------------------------------------------------
void ofApp::setup(){
    a= ofVec3f(-1500,-800,100);  // winter
    ofBackgroundGradient(ofColor::gray, ofColor(255));
    ground.set(10000, 10000, 1000, 1000);       // really big
    ground.rotateDeg(-90, glm::vec3(1,0,0));    // turn horizontal
    ground.move(0, -1000, 0);                    // move down
    gravity = ofVec3f(0,-.1,0);
//
//    for (int i=0;i<=500;i++)
//    {
//        b[i].x=ofRandom(-6000,6000);
//        b[i].y=-1000;
//        b[i].z=ofRandom(-6000,6000);
//        radius[i] = ofRandom(100,200);
//
//    }
   
   
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<25; i++)
    {
        Particle p;
        p.vel.x = ofRandom(-10,10);
        p.vel.y = ofRandom(0,0);
        p.vel.z = ofRandom(-10,10);
        p.lifespan = ofRandom(1,3);
        p.mass = ofRandom(.7,1.3);
        eruption.push_back(p);
    }
     
    while (eruption.size() > 5000)
    {
        eruption.erase(eruption.begin());
    }
    
    for (int i=0; i<eruption.size(); i++)
    {
        eruption[i].applyForce(gravity);
        eruption[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    cam.begin();
    ofDisableAlphaBlending();
    ofEnableDepthTest();
    
    ofDisableArbTex();
    ofPushStyle();
    ofSetColor( ofColor::white);
    ground.draw();
    
    for (int i=0; i<eruption.size(); i++)
    {
        eruption[i].draw();
    }
    
    ofPopStyle();
   
    
    
    //------- w
    ofPushStyle();
    ofSetColor(ofColor(25,25,112));
    mesh.enableIndices();
    ofSetLineWidth(80);
    p1 =ofVec3f(a.x,a.y+520,a.z);
    p2 =ofVec3f(a.x+200,a.y,a.z);
    p3 =ofVec3f(a.x+400,a.y+520,a.z);
    p4 =ofVec3f(a.x+600,a.y,a.z);
    p5 =ofVec3f(a.x+800,a.y+520,a.z);
   
    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh.addVertex(p1);
    mesh.addVertex(p2);
    mesh.addVertex(p3);
    mesh.addVertex(p4);
    mesh.addVertex(p5);

    mesh.addIndex(0);
    mesh.addIndex(1);
    mesh.addIndex(1);
    mesh.addIndex(2);
    mesh.addIndex(2);
    mesh.addIndex(3);
    mesh.addIndex(3);
    mesh.addIndex(4);
    
    //------------ i
    p6 = ofVec3f(a.x+1000, a.y+520, a.z);
    p7 = ofVec3f(a.x+1000, a.y, a.z);
    mesh.addVertex(p6);
    mesh.addVertex(p7);
    mesh.addIndex(5);
    mesh.addIndex(6);
    
    mesh.draw();
    
    //----------- n
    n1 = ofVec3f(a.x+1200, a.y, a.z);
    n2 = ofVec3f(a.x+1200, a.y+520, a.z);
    n3 = ofVec3f(a.x+1600, a.y, a.z);
    n4 = ofVec3f(a.x+1600, a.y+520, a.z);
    mesh.addVertex(n1);
    mesh.addVertex(n2);
    mesh.addVertex(n3);
    mesh.addVertex(n4);
    mesh.addIndex(7);
    mesh.addIndex(8);
    mesh.addIndex(8);
    mesh.addIndex(9);
    mesh.addIndex(9);
    mesh.addIndex(10);
   
    mesh.draw();
    
    //-------- e
    e1 = ofVec3f(a.x+1800, a.y+500, a.z);
    e2 = ofVec3f(a.x+1800, a.y+260, a.z);
    e3 = ofVec3f(a.x+1800, a.y, a.z);
    e4 = ofVec3f(a.x+2200, a.y+500, a.z);
    e5 = ofVec3f(a.x+2200, a.y+260, a.z);
    e6 = ofVec3f(a.x+2200, a.y, a.z);

    mesh.addVertex(e1);
    mesh.addVertex(e2);
    mesh.addVertex(e3);
    mesh.addVertex(e4);
    mesh.addVertex(e5);
    mesh.addVertex(e6);

    mesh.addIndex(14);
    mesh.addIndex(11);
    mesh.addIndex(11);
    mesh.addIndex(12);
    mesh.addIndex(12);
    mesh.addIndex(15);
    mesh.addIndex(12);
    mesh.addIndex(13);
    mesh.addIndex(13);
    mesh.addIndex(16);
    mesh.draw();
    
    //----------t
    t1 = ofVec3f(a.x+2390, a.y+500, a.z);
    t2 = ofVec3f(a.x+2600, a.y+500, a.z);
    t3 = ofVec3f(a.x+2810, a.y+500, a.z);
    t4 = ofVec3f(a.x+2600, a.y, a.z);
    mesh.addVertex(t1);
    mesh.addVertex(t2);
    mesh.addVertex(t3);
    mesh.addVertex(t4);
    mesh.addIndex(17);
    mesh.addIndex(18);
    mesh.addIndex(18);
    mesh.addIndex(19);
    mesh.addIndex(18);
    mesh.addIndex(20);
    mesh.draw();
    
    //----------r
    r1 = ofVec3f(a.x+3000, a.y+500, a.z);
    r2 = ofVec3f(a.x+3400, a.y+375, a.z);
    r3 = ofVec3f(a.x+3000, a.y+250, a.z);
    r4 = ofVec3f(a.x+3000, a.y, a.z);
    r5 = ofVec3f(a.x+3400, a.y, a.z);

    mesh.addVertex(r1);
    mesh.addVertex(r2);
    mesh.addVertex(r3);
    mesh.addVertex(r4);
    mesh.addVertex(r5);
    mesh.addIndex(21);
    mesh.addIndex(22);
    mesh.addIndex(22);
    mesh.addIndex(23);
    mesh.addIndex(23);
    mesh.addIndex(24);
    mesh.addIndex(23);
    mesh.addIndex(25);
    mesh.draw();
    
    ofPopStyle();
        cam.end();
    
//    ofDrawBitmapStringHighlight("Press'U' to go up \n 'D' to go down \n 'L' to go left \n 'R' to go right \n sapce key to stop", ofVec2f(20,20));
    
   
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
