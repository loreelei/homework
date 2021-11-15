#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    pos3=glm::vec2(ofGetWidth()*0.78, ofGetHeight()*0.7);
    pos1=glm::vec2(20, 20); //circle
    pos2=glm::vec2(ofGetWidth()-20, 20); //circle
//    pos4 = glm::vec2(0,0);
    ofSetFrameRate(10.);
//    ofSetBackgroundColor(255,240,245);
   
    glm::vec2 centerScreen =
        glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    
    
    particle1.mass = 10.0;
    particle1.pos  = pos1;
    
    particle2.mass = 10.0;
    particle2.pos  = pos2;
    distance = glm::length(pos3-pos4);
    m=30;
    
    myImage.load("heart1.png");
      myImage.setImageType(OF_IMAGE_COLOR);
      myImage2.load("heart2.jpeg");
      myImage2.setImageType(OF_IMAGE_COLOR);
      
      imgWidth = myImage.getWidth();
      imgHeight = myImage.getHeight();
    
   
}

//--------------------------------------------------------------
void ofApp::update(){

    
    glm::vec2 diff1 = particle2.pos - particle1.pos;     // direction vector to target (mouse)
    glm::vec2 diff2 = particle1.pos - particle2.pos;
    
    particle1.addForce(diff1 * 0.05);               // attraction force (push in the direction of target)
    particle2.addForce(diff2 * 0.05);
    
    particle1.addDampingForce(0.1);
    particle2.addDampingForce(0.1);
    
    particle1.update();
    particle2.update();
    if (glm::length(particle1.pos-particle2.pos)<=100 && glm::length(particle1.pos-particle2.pos)>0)
    {
       
        pos3+=(pos4-pos3)/glm::length(pos3-pos4)*20;
        pos4+=(pos3-pos4)/glm::length(pos3-pos4)*20;
        imgWidth +=20;
        imgHeight +=20;
//        ofVec2f move1 = ofMap(glm::length(particle1.pos-particle.pos2), 100,500, );
    }
    
   
    
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor colorOne(255,182,193);
    ofColor colorTwo(255,240,245);
    ofBackgroundGradient(colorOne, colorTwo,OF_GRADIENT_CIRCULAR);
   
    particle1.draw();
    particle2.draw();

    
    
      myImage.draw(pos3, 0.5*ofRandom(imgWidth-10,imgWidth), 0.5*ofRandom(imgHeight-10,imgHeight));
      myImage2.draw(pos4, 0.5*ofRandom(imgWidth-10,imgWidth), 0.5*ofRandom(imgHeight-10,imgHeight));
      
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
    pos4=glm::vec2(x, y);
//    distance = glm::length(pos3-pos4);
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
