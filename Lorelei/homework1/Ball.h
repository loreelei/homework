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

        Ball();                // "constructor" function - required for every class
                            // this is automatically called whenever we create a new ball
        void setMode(particleMode newMode);
        void update();
        void draw();
        
        float radius11;
        float radius12;
        float radius13;// size
        float radius2;        // size
        float radius31;        // size
        float radius32;        // size
        float minRadius;
        float maxRadius;// size
        
        float x11, y11;
        float x12, y12;
        float x2, y2;
        float x31, y31;
        float x32, y32;
        float x4, y4;
        
        float dirX11, dirY11;
        float dirX12, dirY12;
        float dirX2, dirY2;
        float dirX31, dirY31;
        float dirX32, dirY32;
//    float dirX321, dirY321;
//    float dirX322, dirY322;
//    float dirX323, dirY323;
//    float dirX324, dirY324;
        float dirX4, dirY4; // "direction" (a.k.a. velocity or speed)
        
        ofColor color;
        particleMode mode;
        
};
