#include "Ball.h"

// constructor
Ball::Ball() {
//    x = ofGetHeight();
    y = ofGetHeight();
    velocity = 5;
}
void Ball::setup() {
//    pos.x = ofGetWidth();
//    pos.y = ofGetHeight();
}

// update position, etc.
void Ball::update() {
    
//    x+=velocity;
//    if (x<=(ofGetWidth()/2+300)){
//        x=(ofGetWidth()/2+300);
//        velocity*=-1;
//    }
//    else if (x>=(ofGetWidth()/2+700)){
//        x=ofGetWidth()/2+700;
//        velocity*=-1;
//    }
//
}
    




// draw the ball
void Ball::draw() {
    ofSetColor(0,0,0);
    x = ofGetMouseX();
    x+=velocity;
    if (x<=(ofGetWidth()/2)){
        x=(ofGetWidth()/2);
        velocity*=-1;
    }
    else if (x>=(ofGetWidth()/2+200)){
        x=ofGetWidth()/2+200;
        velocity*=-1;
    }
    
    ofDrawEllipse(x, y/2,50,70);
}
