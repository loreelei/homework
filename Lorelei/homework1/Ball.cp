#include "Ball.h"

// constructor
Ball::Ball() {
    //-------------------spring flower
    x11 = ofRandom(radius11, ofGetWidth()  - radius11);
    y11 = ofRandom(radius11, ofGetHeight() - radius11);
    dirX11 = ofRandom(-2,2);
    dirY11 = ofRandom(-2,1);
    //-------------------butterfly
    x12 = ofRandom(radius12, ofGetWidth()  - radius12);
    y12 = ofRandom(radius12, ofGetHeight() - radius12);
    dirX12 = ofRandom(-5,5);
    dirY12 = ofRandom(-5,5);
    //----------------summer fireworm
    x2 = ofRandom(radius2, ofGetWidth()  - radius2);
    y2  = ofRandom(radius2, ofGetHeight() - radius2);
    dirX2 = ofRandom(-5,5);
    dirY2 = ofRandom(-3,3);
    //----------------autumn rain
//    radius32=2;
    radius31=10;
    x32 = ofRandom(0, ofGetWidth());
    y32 = ofRandom(0, (ofGetHeight() - radius31)/3);
    dirX32 = ofRandom(-2,2);
    dirY32 = ofRandom(7,10);
    //---------------autumn cloud
    x31 = ofRandom(radius31, ofGetWidth()  - radius31);
    y31  = ofRandom(radius31, (ofGetHeight() - radius31));
    dirX31 = ofRandom(-3,3);
    dirY31 = 0;
    //---------------winter snow
    x4 = ofRandom(maxRadius, ofGetWidth()  - maxRadius);
    y4  = ofRandom(maxRadius, ofGetHeight() - maxRadius);
    dirX4 = ofRandom(-2,2);
    dirY4 = ofRandom(0,2);

//    // inside the constructor you initialize the object's variables
//
//    // random radius between 10 and 50
//    radius = ofRandom(10,50);
//
//    // random color
//    float red    = ofRandom(0,255);
//    float green    = ofRandom(0,255);
//    float blue    = ofRandom(0,255);
//    color = ofColor(red, green, blue);
//
//    // random position in window
//    x = ofRandom(radius, ofGetWidth()  - radius);
//    y = ofRandom(radius, ofGetHeight() - radius);
//
//    // random x and y speeds/directions between -10 and 10
//    dirX = ofRandom(-10,10);
//    dirY = ofRandom(-10,10);
}
//-------------------------------
void Ball::setMode(particleMode newMode){
    mode = newMode; 
}
// update position, etc.
void Ball::update() {
    if (mode == SPRING){
        x11+=dirX11;    // move along x by amount of dirX
        y11+=dirY11;    // move along y by amount of dirY
        // check left
        if (x11 <= radius11) {
            x11 = radius11;
            dirX11 = -dirX11;
        }
        // check right
        else if (x11 >= ofGetWidth() - radius11) {
            x11 = ofGetWidth() - radius11;            // similar to above
            dirX11 = -dirX11;
        }
        // check top and bottom
        if (y11 <= radius11) {
            y11 = radius11;
            dirY11 = -dirY11;
        }
        else if (y11 >= ofGetHeight() - radius11) {
            y11 = ofGetHeight() - radius11;
            dirY11 = -dirY11;
        }
        x12+=dirX12;    // move along x by amount of dirX
        y12+=dirY12;    // move along y by amount of dirY
        // check left
        if (x12 <= radius12) {
            x12 = radius12;
            dirX12 = -dirX12;
        }
        // check right
        else if (x12 >= ofGetWidth() - radius12) {
            x12 = ofGetWidth() - radius12;            // similar to above
            dirX12 = -dirX12;
        }
        // check top and bottom
        if (y12 <= radius12) {
            y12 = radius12;
            dirY12 = -dirY12;
        }
        else if (y12 >= ofGetHeight() - radius12) {
            y12 = ofGetHeight() - radius12;
            dirY12 = -dirY12;
        }
    }
    else if (mode == SUMMER){
        x2+=dirX2;    // move along x by amount of dirX
        y2+=dirY2;    // move along y by amount of dirY
        // check left
        if (x2 <= radius2) {
            x2 = radius2;
            dirX2 = -dirX2;
        }
        // check right
        else if (x2 >= ofGetWidth() - radius2) {
            x2 = ofGetWidth() - radius2;            // similar to above
            dirX2 = -dirX2;
        }
        // check top and bottom
        if (y2 <= radius2) {
            y2 = radius2;
            dirY2 = -dirY2;
        }
        else if (y2 >= ofGetHeight() - radius2) {
            y2 = ofGetHeight() - radius2;
            dirY2 = -dirY2;
        }
    }
    else if (mode == AUTUMN){
        x31+=dirX31;    // move along x by amount of dirX
        y31+=dirY31;    // move along y by amount of dirY
        x32+=dirX32;    // move along x by amount of dirX
        y32+=dirY32;    // move along y by amount of dirY
        
        // check left
        if (x31 <= radius31) {
            x31 = radius31;
            dirX31 = -dirX31;
        }
        // check right
        else if (x31 >= ofGetWidth() - radius31) {
            x31 = ofGetWidth() - radius31;            // similar to above
            dirX31 = -dirX31;
        }
        if (x32 <= radius32) {
            x32 = radius32;
            dirX32 = -dirX32;
        }
        // check right
        else if (x32 >= ofGetWidth() - radius32) {
            x32 = ofGetWidth() - radius32;            // similar to above
            dirX32 = -dirX32;
        }
    }
    else if (mode == WINTER){
        x4+=dirX4;    // move along x by amount of dirX
        y4+=dirY4;    // move along y by amount of dirY
        // check left
        if (x4 <= maxRadius ) {
            x4 = maxRadius;
            dirX4 = -dirX4;
        }
        // check right
        else if (x4 >= ofGetWidth() - maxRadius) {
            x4 = ofGetWidth() - maxRadius;            // similar to above
            dirX4 = -dirX4;
        }
        // check top and bottom
        if (y4 <= maxRadius) {
            y4 = maxRadius;
            dirY4 = -dirY4;
        }
        else if (y4 >= ofGetHeight() - maxRadius) {
            y4 = ofGetHeight() - maxRadius;
            dirY4 = -dirY4;
        }
    }
}
//    x+=dirX;    // move along x by amount of dirX
//    y+=dirY;    // move along y by amount of dirY
//
//    // check for bounces at edges of window:
//
//    // check left
//    if (x <= radius) {
//        x = radius;            // set the position back to the edge of window
//        dirX = -dirX;        // and reverse direction
//    }
//    // check right
//    else if (x >= ofGetWidth() - radius) {
//        x = ofGetWidth() - radius;            // similar to above
//        dirX = -dirX;
//    }
//
//    // check top and bottom
//    if (y <= radius) {
//        y = radius;
//        dirY = -dirY;
//    }
//    else if (y >= ofGetHeight() - radius) {
//        y = ofGetHeight() - radius;
//        dirY = -dirY;
//    }



// draw the ball
void Ball::draw() {
    if (mode == SPRING){
        ofSetBackgroundColor(245,245,220);
    //---------------------spring flower
    radius11 = 15;
    float distance = 35;
    float circlenumber = 12;
    ofSetColor(255,192,203);
    ofDrawCircle(x11,y11,radius11);
    int angle = 30;
    for (int i =0; i<=circlenumber; i++){
        float xOffset = cos(angle) * distance;
        float yOffset = sin(angle) * distance;
        ofDrawCircle(x11+xOffset,y11+yOffset,radius11);
        ofDrawLine(x11,y11,x11+xOffset,y11+yOffset);
        angle +=30;
        
    }
    //-------------------butterfly
    radius12 = ofRandom(10,20);
        ofSetColor(65,105,225);
    ofDrawCircle(x12-radius12/2,y12+radius12/2,radius12/2);
    ofDrawCircle(x12+radius12/2,y12+radius12/2,radius12/2);
    ofDrawCircle(x12-radius12,y12-radius12,radius12);
    ofDrawCircle(x12+radius12,y12-radius12,radius12);
//    ofDrawEllipse(x12+radius12,y12,radius12,radius12*3);
    }
    else if (mode == SUMMER){
        ofSetBackgroundColor(100,100,112);
    //--------------------moon
        ofSetColor(255,255,100);
        ofDrawEllipse(200,300,100,80);
        ofSetColor(100,100,112);
        ofDrawEllipse(230,330,100,100);
    //--------------------fireworm
        radius2 = ofRandom(5,10);
        ofSetColor(255,215,0);
        ofDrawCircle(x2,y2,radius2);
        ofDrawCircle(x2+5,y2+5,radius2);
        
    }
    else if (mode == AUTUMN){
        //--------------cloud
        ofSetBackgroundColor(240,255,255);
        ofSetColor(135,206,235);
        ofDrawEllipse(x31,y31,80,40);
        ofDrawEllipse(x31+60,y31,120,80);
        ofDrawCircle(x31+30,y31-30,40);
        //---------------rain
//        ofDrawEllipse(x32,y32,10,20);
//        ofDrawEllipse(x32+60,y32,10,20);
//        ofDrawEllipse(x32-20,y32+40,10,20);
//        ofDrawEllipse(x32+100,y32-50,10,20);
//        ofDrawEllipse(x32-25,y32+80,10,20);
//
       
    }
    else if (mode == WINTER){
        int numLines = 200;
        minRadius = 10;
        maxRadius = 25;
        ofSetBackgroundColor(80,80,112);
        for (int i=0; i<numLines; i++) {
            float angle = ofRandom(ofDegToRad(360.0));
            float distance = ofRandom(minRadius, maxRadius);
            float xOffset = cos(angle) * distance;
            float yOffset = sin(angle) * distance;
            float alpha = ofMap(distance, minRadius, maxRadius, 50, 0);  // Make shorter lines more opaque
            ofSetColor(255, alpha);
            ofDrawLine(x4, y4, x4+xOffset, y4+yOffset);
        }
    }
    
    
    
}
