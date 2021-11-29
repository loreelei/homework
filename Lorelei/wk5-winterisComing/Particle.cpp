#include "Particle.hpp"

Particle::Particle()
{
    
    pos            = glm::vec3(ofRandom(-7000,7000),ofRandom(7000),ofRandom(-7000,7000));
    vel.x        = ofRandom(-1,1);
    vel.y        = ofRandom(-1,1);
    vel.z        = ofRandom(-1,1);
    lifespan        = ofRandom(10,20); // seconds
    mass            = ofRandom(1,3);
    lastUpdateTime  = ofGetElapsedTimef();
    size = ofRandom(5,10);
}

Particle::Particle(glm::vec3 _pos, glm::vec3 _vel, float _life, float _mass)
{
    pos            = _pos;
    vel            = _vel;
    lifespan    = _life;
    mass        = _mass;
    lastUpdateTime = ofGetElapsedTimef();
}

void Particle::applyForce(glm::vec3 force)
{
    acc += force / mass;
}

void Particle::applyDrag(float amt)
{
    float speed = glm::length(vel);
    if (speed > 0) {
        applyForce( -vel / speed * amt );
    }
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
    
    // update age
    age += ofGetElapsedTimef() - lastUpdateTime;    // + time diff
    lastUpdateTime = ofGetElapsedTimef();
    
    if (size > 1){
        size -=0.07;
    }
}

void Particle::draw()
{
    ofPushStyle();

    ofColor fire    = ofColor(255, 255, 255);
    ofColor smoke    = ofColor(96,96,96);

    float lerp        = ofClamp(age/lifespan, 0, 1);
    ofColor color    = fire.getLerped( smoke, lerp);
    ofSetColor( color );

    material.setEmissiveColor( color );
    material.begin();

    float radius        = lifespan*5;
    
    ofDrawSphere(pos, radius);
    
    material.end();
    
    ofPopStyle();
    
    
}
