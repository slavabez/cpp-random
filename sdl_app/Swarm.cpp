//
// Created by slava on 02/10/17.
//

#include "Swarm.h"

Swarm::Swarm() : m_pParticles(new Particle[N_PARTICLES]) {

}

Swarm::~Swarm() {
    delete [] m_pParticles;
}
