#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class ofApp : public ofBaseApp{

public:
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
    
//    ofIcoSpherePrimitive volcano;
    ofPlanePrimitive ground;

    vector<Particle> eruption;
    
    ofLight firelight;    // point light
    ofLight sunlight;    // directional light
    
    ofEasyCam cam;
    
    glm::vec3 gravity;
    
    ofPoint a[5050];
    
    float radius[5000];
    
    int _x,_y;
    
    
        
};
