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
        
        vector<Particle> eruption;
        ofSpherePrimitive sphere;
        ofPlanePrimitive ground;
        ofBoxPrimitive box;
        ofLight light;
        ofTexture mTex1, mTex2;
        ofEasyCam cam;
    ofVec3f p1,p2,p3,p4,p5, p6, p7;
    ofVec3f vertex;
    ofVec3f n1,n2,n3,n4;
    ofVec3f e1,e2,e3,e4, e5,e6;
    ofVec3f t1,t2,t3,t4;
    ofVec3f r1,r2,r3,r4, r5;
    
    ofMesh mesh;
    ofVec3f vel;
    ofPoint b[5000];
    ofVec3f a;
    ofConePrimitive grass[5000];
    float radius[5000];
    
    glm::vec3 gravity;
};
