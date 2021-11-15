//
//  Particle.hpp
//  wk06_particle_system
//
//  Created by Tyler Henry on 10/2/18.
//

#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass);
    
    void addForce(glm::vec2 force);
    void addDampingForce(float strength);
    void update();
    void draw();
    
    glm::vec2 pos, vel, acc;
    float mass;
    float length;
    
};
