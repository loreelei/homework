// Ball.h

/* #pragma once should always be at the top of your header files
 * it prevents other headers like "ofMain.h" from being included more than once in your app
 * (note that ofMain.h is also included in ofApp.h)
 */

#pragma once
#include "ofMain.h"        // ofMain.h lets our Ball "see" openFrameworks

enum particleMode{
    SPRING = 0,
    SUMMER,
    AUTUMN,
    WINTER
};

class Ball{

    public:        // other classes can access the following functions & variables:

//        Ball();                // "constructor" function - required for every class
                            // this is automatically called whenever we create a new ball
        void setup(float m);
        void update();
        void applyForce(ofPoint force);
        void draw();
        void checkEdges();
        
        ofPoint location;
        ofPoint velocity;
        ofPoint acceleration;
        
        float mass;
    float radius; 
        ofColor color;
      
        
};
