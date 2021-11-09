// Ball.h

/* #pragma once should always be at the top of your header files
 * it prevents other headers like "ofMain.h" from being included more than once in your app
 * (note that ofMain.h is also included in ofApp.h)
 */

#pragma once
#include "ofMain.h"        // ofMain.h lets our Ball "see" openFrameworks


class Ball{

    public:        // other classes can access the following functions & variables:

        Ball();                // "constructor" function - required for every class
                            // this is automatically called whenever we create a new ball
//        void setup(float m);
        void update();
        void applyForce(ofPoint force);
        void draw();
        void checkEdges();
        
        ofPoint pos1;
        ofPoint pos2;
        ofPoint pos3;
        ofPoint mouse;
        
        float mass;
    float radius;
        ofColor color;
    float x0,y0;
    float x1,y1;
    float x2,y2;
    float x3,y3;
    float x4,y4;
    float x5,y5;
    float x6,y6;
    float xoffSet1,yoffSet1;
    float distance;
    float m;
    float r1,b1,g1;
    float r2,b2,g2;
    
    
        
};
