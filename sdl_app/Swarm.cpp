//
// Created by slava on 02/10/17.
//

#include <clocale>
#include "Swarm.h"

Swarm::Swarm() : m_pParticles(new Particle[N_PARTICLES]) {

}

Swarm::~Swarm() {
    delete [] m_pParticles;
}

void Swarm::update() {
    for (int i = 0; i < Swarm::N_PARTICLES; i++) {
        m_pParticles[i].update();
    }

}
