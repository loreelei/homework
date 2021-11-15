
//

#include "Particle.hpp"

Particle::Particle()
{
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,2);
    acc = glm::vec2(0,0);
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    pos = _pos;
    vel = _vel;
    mass = _mass;
}

void Particle::addForce(glm::vec2 force)
{
    acc += force / mass;
}

void Particle::addDampingForce(float strength)
{
    float length = glm::length(vel);
    if (length != 0){                       // prevent illegally dividing by zero if vel is 0
        acc -= vel / length * strength;     // drag
    }
}

void Particle::update()
{
    
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Particle::draw()
{
    ofPushStyle();
    ofSetColor(0,0,0);
    ofDrawBitmapStringHighlight("click mouse to move the heart", 10, ofGetHeight()-100);
    ofPopStyle();
    
    ofPushStyle();
    float hue = ofMap(mass, 0, 10, 0, 255);
    ofSetColor(ofColor::fromHsb(hue,255,255));
    ofDrawCircle(pos,mass * 2);
    ofDrawRectangle(pos.x-mass/2,pos.y, mass/3,mass*8);
    ofSetLineWidth(mass/3);
    ofDrawLine(pos.x-mass/2,pos.y+mass*3, pos.x-mass*3,pos.y+mass*5);
    ofDrawLine(pos.x-mass/2,pos.y+mass*3, pos.x+mass*3,pos.y+mass*5);
    ofDrawLine(pos.x-mass/2,pos.y+mass*6, pos.x-mass*3,pos.y+mass*9);
    ofDrawLine(pos.x-mass/2,pos.y+mass*6, pos.x+mass*3,pos.y+mass*9);
    ofPopStyle();
}

