#include "ofApp.h"
//ofVec3f a(100,10,100);

//--------------------------------------------------------------
void ofApp::setup(){
    a= ofVec3f(100,10,100);
    ofBackground(ofColor(135,206,235));
   
    ground.set(10000, 10000, 1000, 1000);       // really big
    ground.rotateDeg(-90, glm::vec3(1,0,0));    // turn horizontal
    ground.move(0, -1000, 0);                    // move down
    
//    for (int i=0;i<=300;i++)
//    {
//        b[i].x= ofRandom(-1000,1000);
//        b[i].y=0;
//        b[i].z=ofRandom(-6000,6000);
//        grass[i].setPosition(b[i]);
//        grass[i].setRadius(ofRandom(10,20));
//        grass[i].setHeight(ofRandom(10,20));
//        grass[i].rotateDeg(ofRandom(0,180),0.0,1.0,0.0);
//    }
    for (int i=0;i<=300;i++)
    {
        b[i].x=ofRandom(-6000,6000);
        b[i].y=-1000;
        b[i].z=ofRandom(-6000,6000);
        radius[i] = ofRandom(100,200);
      
    }
   
   
    
}

//--------------------------------------------------------------
void ofApp::update(){
    a+=vel;
//    ofVec3f pos = mesh.getVertex(0);
//    pos.y+=1;
//    for(int i=0; i<mesh.getNumVertices(); i++){
////        ofVec3f pos = mesh.getVertex(i);
////        pos.y+=1;
//        firework.setVertex(i, firework.getVertex(i) + ofVec3f(0,1,0));
//    }
//    for(int i=0; i<mesh.size(); i++){
      for(int j=0; j<mesh.getNumVertices(); j++){
        mesh.setVertex(j, mesh.getVertex(j) + vel);
      }
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
     ofLoadImage(mTex1,"color.jpeg");
     ofLoadImage(mTex2,"weave.jpeg");
    
    cam.begin();
    ofDisableAlphaBlending();
    ofEnableDepthTest();
    
   
    
    //------- stripe
    mesh.enableIndices();
    top1 =ofVec3f(a.x-350,a.y+1500,a.z);
    top2 =ofVec3f(a.x+350,a.y+1500,a.z);
    p1 =ofVec3f(a.x-150,a.y,a.z);
    p2 =ofVec3f(a.x+150,a.y,a.z);
   
    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh.addVertex(top1);
    mesh.addVertex(top2);
    mesh.addVertex(p1);
    mesh.addVertex(p2);
    mesh.addIndex(0);
    mesh.addIndex(2);
    mesh.addIndex(1);
    mesh.addIndex(3);
    ofSetLineWidth(5);
    mesh.draw();
    
    
    //--------- body
    sphere.setRadius(1000);
    sphere.setPosition(a.x,a.y+2000,a.z);
    box.setWidth(300);
    box.setHeight(200);
    box.setDepth(300);
    box.setPosition(a);
    ofDisableArbTex();
    ofPushStyle();
    ofSetColor(ofColor::forestGreen);
    ground.draw();
    ofPopStyle();
    mTex1.bind();
    sphere.draw();
    mTex1.unbind();
    mTex2.bind();
    box.draw();
    mTex2.unbind();
    
    //------------ grass
    
//    for (int i=0; i<=300; i++){
//        ofPushStyle();
//        ofSetColor(ofColor::forestGreen);
//
//        grass[i].draw();
//        ofPopStyle();
    //---------------------
        for (int i=0; i<=200; i++){
            ofPushStyle();
            ofSetColor(102,51,0);
            ofDrawCylinder(b[i], 60,800);
            ofSetColor(0,150,0);
            ofDrawCone(b[i].x, b[i].y+400, b[i].z, 300, -450);
            ofDrawCone(b[i].x, b[i].y+550, b[i].z, 250, -350);
            ofPopStyle();
        }
        
        cam.end();
    
    ofDrawBitmapStringHighlight("Press'U' to go up \n 'D' to go down \n 'L' to go left \n 'R' to go right \n sapce key to stop", ofVec2f(20,20));
    
   
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
           case 'u':
           case 'U':
               vel=ofVec3f (0,3,0);
               break;
               
               
           case 'd':
            case 'D':
            vel=ofVec3f (0,-3,0);
               break;
               
        case 'l':
         case 'L':
//            while (spaceRange !=0) continue;
            vel=ofVec3f (-3,0,-3);
               break;
               
        case 'R':
         case 'r':
//            while (spaceRange !=0) continue;
            vel=ofVec3f (3,0,3);
               break;
        case ' ':
            vel = ofVec3f(0,0,0);
            break;
            
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
