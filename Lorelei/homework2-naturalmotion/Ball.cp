#include "Ball.h"


Ball::Ball(){
    x0=ofGetWidth()/2;
    y0=ofGetHeight()/2;
    m=0;
    r1=10;
    g1=10;
    b1=10;
    r2=50;
    g2=70;
    b2=100;
}



// update position, etc.
void Ball::update() {
    ofSetFrameRate(10);
    m+=1;
    if(ofGetMousePressed()){
        m+=3;
    }
//    for (int i=0;i<=5;i++){
//    r1+=10;
//    b1+=10;
//    g1+=10;
//    r2+=10;
//    b2+=10;
//    g2+=10;
//    }
    
    
   
}



// draw the ball
void Ball::draw() {
    
    ofBackgroundGradient(ofColor(r1,g1,b1), ofColor(r2,g2,b2),OF_GRADIENT_LINEAR);
    ofSetColor(255);
    ofDrawBitmapString("Try press/move the mouse", 50, 50);
    radius = 80;
    //----------bottom
    ofNoFill();
    ofSetLineWidth(20);
    ofSetColor(220,220,220);
    pos1.set(ofGetWidth()/2,ofGetHeight()/2);
    pos2.set((ofGetWidth()/2)-100,ofGetHeight());
    pos3.set((ofGetWidth()/2)+100,ofGetHeight());
    ofDrawTriangle(pos1,pos2,pos3);
    
    //-----------body
    float distance = 300;
//    ofSetColor(105,105,105);
    ofDrawCircle(pos1,distance);
    ofDrawCircle(pos1,distance-50);

    ofFill();
    float yoffSet1= sin((m+0)*PI/180)*distance;
    float xoffSet1= cos((m+0)*PI/180)*distance;
    x1=x0+xoffSet1;
    y1=y0+yoffSet1;
    ofDrawLine(x0,y0,x1,y1);
    float yoffSet2= sin((60+m)*PI/180)*distance;
    float xoffSet2= cos((60+m)*PI/180)*distance;
    x2=x0+xoffSet2;
    y2=y0+yoffSet2;
    ofDrawLine(x0,y0,x2,y2);
    
    float yoffSet3= sin((120+m)*PI/180)*distance;
    float xoffSet3= cos((120+m)*PI/180)*distance;
    x3=x0+xoffSet3;
    y3=y0+yoffSet3;
    ofDrawLine(x0,y0,x3,y3);
    
    float yoffSet4= sin((180+m)*PI/180)*distance;
    float xoffSet4= cos((180+m)*PI/180)*distance;
    x4=x0+xoffSet4;
    y4=y0+yoffSet4;
    ofDrawLine(x0,y0,x4,y4);
    
    float yoffSet5= sin((240+m)*PI/180)*distance;
    float xoffSet5= cos((240+m)*PI/180)*distance;
    x5=x0+xoffSet5;
    y5=y0+yoffSet5;
    ofDrawLine(x0,y0,x5,y5);
    
    float yoffSet6= sin((300+m)*PI/180)*distance;
    float xoffSet6= cos((300+m)*PI/180)*distance;
    x6=x0+xoffSet6;
    y6=y0+yoffSet6;
    ofDrawLine(x0,y0,x6,y6);
    
    ofSetFrameRate(5);
    ofSetColor(ofRandom(200,250),ofRandom(100,150),ofRandom(100,150));
    ofDrawCircle(x1,y1,radius);
    ofSetColor(ofRandom(200,250),ofRandom(100,150),ofRandom(100,150));
    ofDrawCircle(x2,y2,radius);
    ofSetColor(ofRandom(200,250),ofRandom(100,150),ofRandom(100,150));
    ofDrawCircle(x3,y3,radius);
    ofSetColor(ofRandom(200,250),ofRandom(100,150),ofRandom(100,150));
    ofDrawCircle(x4,y4,radius);
    ofSetColor(ofRandom(200,250),ofRandom(100,150),ofRandom(100,150));
    ofDrawCircle(x5,y5,radius);
    ofSetColor(ofRandom(200,250),ofRandom(100,150),ofRandom(100,150));
    ofDrawCircle(x6,y6,radius);
    
    ofSetFrameRate(0.01);
    ofSetColor(250,250,210);
    for (int i=0;i<=20;i++){
        ofDrawCircle(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),1);
    }
    
    
}
