#include "Ball.h"

// constructor
//Ball::Ball() {
//    //-------------------spring flower
//    radius = ofRandom(40,50);
//    time = ofGetElapsedTimef();
//    x=ofRandom(radius,ofGetWidth()-radius);
//
////    dirX11 = ofRandom(-2,2);
////    dirY11 = ofRandom(-2,1);
//
//
//}
void Ball::setup(float m) {
    radius = ofRandom(20,30);
    float x=ofRandom(radius,ofGetWidth()-radius);
    float y=ofRandom(radius,ofGetHeight()-radius);
    mass = m;
    location.set(x,y);
    velocity.set(0,0);
    acceleration.set(0,0);
}

void Ball::applyForce(ofPoint force){
    ofPoint f;
    f = force/mass;
    acceleration += f;
}

// update position, etc.
void Ball::update() {
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
//        x+=radius;    // move along x by amount of dirX
           // move along y by amount of dir
}



// draw the ball
void Ball::draw() {
    
    float x= location.x;
    float y=location.y;
    //    time = ofGetElapsedTimef();
//    x=ofRandom(radius,ofGetWidth()-radius);
    ofSetColor(255,204,0);
    ofDrawCircle(x,y,radius);
    ofSetColor(0,0,0);
    ofSetLineWidth(3);
    ofDrawLine(x+radius-5,y,x+radius+7,y);
    ofDrawCircle(x+radius/2,y,radius/3);

    ofPath path;
    path.moveTo(x-radius/2, y-radius/2);
    path.arc(x-radius/2, y-radius/2,radius*0.7,radius,0, 180);
    path.draw();
}

void Ball::checkEdges(){
    if (location.x > ofGetWidth()) {
        location.x = 0;
        velocity.x *= 1;
    }
    else if (location.x < 0){
        velocity.x *= 1;
        location.x = ofGetWidth();
    }
    
    if (location.y > ofGetHeight()) {
        velocity.y *= -1;
        location.y = ofGetHeight();
    }


}
