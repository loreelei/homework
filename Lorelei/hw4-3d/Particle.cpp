#include "Particle.hpp"

Particle::Particle()
{
    
    pos            = glm::vec3(ofRandom(-2000,2000),ofRandom(700,700),ofRandom(-2000,2000));
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

    ofColor fire    = ofColor(ofRandom(0,255), 50, ofRandom(100,150));
    ofColor smoke    = ofColor(34, 32, 30);

    float lerp        = ofClamp(age/lifespan, 0, 1);
    ofColor color    = fire.getLerped( smoke, lerp);
    ofSetColor( color );

    material.setEmissiveColor( color );
    material.begin();

//    float radius        = ofMap(age, 0, lifespan, 1, 15);

    ofDrawSphere(pos, size);

    material.end();

    ofPopStyle();
    
    
//    ofPushStyle();
//    float hue = ofMap(mass, 0, 5, 0, 255);
//    float sat = 255;
//    float brt = 255;
//
//    float aliveTime = ofGetElapsedTimef() - age;
//    float alpha = ofMap(aliveTime, 0, 2, 255, 0, true);
//
//    ofColor color = ofColor::fromHsb(hue,sat,brt,alpha);
//    ofSetColor(color);
//
//    ofDrawSphere(pos, size);
//    ofPopStyle();
}
