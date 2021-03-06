//
//  Attractor.hpp
//


#pragma once
#include "ofMain.h"

#include "Mover.hpp"
// Attractor class will apply attraction force on Movers

class Attractor {
public:
    
    Attractor();        // default constructor
    Attractor(glm::vec2 _pos);    // alternative constructor
    
    glm::vec2 getForce(Mover m);
    // calculate attraction (or repulsion!)
    
    void draw();
    void update();
    
    glm::vec2 pos;
    float mass;
    
    const float G = .4;        // gravitational constant
    // affects strength of gravity
    float rotation;
};
