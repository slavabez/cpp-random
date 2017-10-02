//
// Created by slava on 01/10/17.
//

#include "Particle.h"
#include <stdlib.h>

Particle::Particle() {
    m_x = ((2.0 * rand()) / RAND_MAX) - 1;
    m_y = ((2.0 * rand()) / RAND_MAX) - 1;
}

Particle::~Particle() {

}

void Particle::update() {
    const double xspeed = 0.001 * rand()/RAND_MAX;
    const double yspeed = 0.001 * rand()/RAND_MAX;

    m_x += xspeed;
    m_y += yspeed;
}
