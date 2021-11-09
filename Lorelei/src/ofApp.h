#pragma once

#include "ofMain.h"
#include "Ball.h"    // include our ball class

class ofApp : public ofBaseApp{

    public:
        ofMesh mesh[1000]; 
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);

    float num;
    ofPoint wind;
        Ball ball;
    float x;
    ofPath path;
    ofPolyline polyline2;
    float b,g,r;
    ofImage myImage;
        
};
