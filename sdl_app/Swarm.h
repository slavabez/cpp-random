//
// Created by slava on 02/10/17.
//

#ifndef PROJECT_SWARM_H
#define PROJECT_SWARM_H

#include "Particle.h"

class Swarm {
public:
    const static int N_PARTICLES = 5000;
private:
    Particle * const m_pParticles;

public:
    Swarm();
    virtual ~Swarm();

    void virtual update();

    Particle * const getParticles() {
        return m_pParticles;
    }
};


#endif //PROJECT_SWARM_H
