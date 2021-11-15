#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    ofVideoGrabber myVideoGrabber;
    ofTexture myTexture;
    ofImage myImage;
    ofImage myImage2;
    unsigned char* invertedVideoData;
    int camWidth;
    int camHeight;
    glm::vec2 pos2;
    glm::vec2 pos1;
    glm::vec2 pos3,pos4;
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
    
    Particle  particle1, particle2;
    float m;
    float distance;
    int imgWidth, imgHeight;
};
