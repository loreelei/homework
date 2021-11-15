//
//  Particle.hpp
//  particlesystem
//
//  Created by Peihan Li on 2021/11/11.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>

#endif /* Particle_hpp */

#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass);
    
    void applyForce(glm::vec2 force);
    void update();
    void draw();
    
    glm::vec2 pos, vel, acc;
    float mass;
    
    float bornTime;
    
};
