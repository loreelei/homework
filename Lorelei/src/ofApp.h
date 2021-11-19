#pragma once

#include "ofMain.h"

class particle {
public:
    // our new particle class
    // with each object containing an x and y position, and a vector direction as vx and vy and a size
    ofColor color;
    float size;
    glm::vec3 force, position, direction;
    int hue;
    
    // we also define two methods that the particle object understands
    void update();
    void draw();
    
    // and define a particle contructor and a destructor (the destructor is denoted by the tilde (~) character prefix
    // the contructor is expecting to be passed an initial x and y co-ordinate for the new particle
    particle(int x, int y,int z, int hue );
    ~particle();
    int key;
   
};

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
//        void keyReleased(int key);
//        void mouseMoved(int x, int y );
//        void mouseDragged(int x, int y, int button);
        void mousePressed(int _x, int _y, int button);
//        void mouseReleased(int x, int y, int button);
    

    // define a vector containing our new particle class objects
    vector<particle> particles;
    vector<particle> mouseparticles;

    ofEasyCam cam;
    ofLight light;
    int hue;
    int maxParticles;
    float x,y,z;
    glm::vec3 force, position, direction;
    glm::vec3 a;
    ofSoundPlayer   mySound;
  
};

