//
//  ParticleSystem.cpp
//  particlesystem
//
//  Created by Peihan Li on 2021/11/11.
//

#include "ParticleSystem.hpp"

#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem()
{
    pos = glm::vec2(0,0);       // default value
    
}

ParticleSystem::ParticleSystem(glm::vec2 _pos)
{
    pos = _pos;                 // assigned value
}

void ParticleSystem::applyForce(glm::vec2 force)
{
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].applyForce(force);
    }
}

void ParticleSystem::update(int numNewParticles, int maxParticles)
{
    
    // create new particles:
    
    for (int i=0; i<numNewParticles; i++)
    {
       
            glm::vec2 vel   = glm::vec2(ofRandom(-1,1), ofRandom(1,-1));
            float mass      = ofRandom(.01, 5);
            Particle particle = Particle(pos,vel,mass);
            particles.push_back(particle);
    
//
//
    }
//
    
    
    // update particles:
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].update();
    }
    
    // erase old particles:
    
    while (particles.size() > maxParticles)     // keep the number of particles under a limit
    {
        particles.erase(particles.begin());     // erase the oldest particle

        particles.pop_back();


//        vector<Particle>::iterator first = particles.begin();
//        auto other = particles.begin();
//
//        auto second = particles.begin() + 3;
//        auto end    = particles.end();
    }
    
}

void ParticleSystem::draw()
{
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].draw();
    }
}
