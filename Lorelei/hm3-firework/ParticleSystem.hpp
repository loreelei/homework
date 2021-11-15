//
//  ParticleSystem.hpp
//  particlesystem
//
//  Created by Peihan Li on 2021/11/11.
//

#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp

#include <stdio.h>

#endif /* ParticleSystem_hpp */

#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem {
public:
    
    // we are now using C++ constructors --
    
    // constructors are functions like setup(), but they run automatically
    // when the object is created in our app
    
    // -- note: constructors do not have a return type
    
    ParticleSystem();                   // default
    ParticleSystem(glm::vec2 _pos);     // "overload" / alternative
    
    void applyForce(glm::vec2 force);   // applies force to particles
    
    void update(int numNewParticles = 5, int maxParticles = 500);
    /*
        numNewParticles:
            how many new particles to create each frame
                (defaults to 10)
        maxParticles:
            maximum number of particles the system will hold
                (defaults to 1000)
     */
    
    
    void draw();
    
    glm::vec2 pos;                      // origin of the particle system
    
    vector<Particle> particles;
    int borntime;
};
