//
// Created by slava on 02/10/17.
//

#include <clocale>
#include "Swarm.h"

Swarm::Swarm() : m_pParticles(new Particle[N_PARTICLES]), lastTime(0) {

}

Swarm::~Swarm() {
    delete [] m_pParticles;
}

void Swarm::update(int elapsed) {

    int interval = elapsed - lastTime;

    for (int i = 0; i < Swarm::N_PARTICLES; i++) {
        m_pParticles[i].update(interval);
    }

    lastTime = elapsed;
}
