//
// Created by slava on 01/10/17.
//

#ifndef PROJECT_PARTICLE_H
#define PROJECT_PARTICLE_H


class Particle {
public:
    double m_x;
    double m_y;

    double m_speed;
    double m_direction;
    void init();


public:
    Particle();
    virtual ~Particle();

    void update(int interval);


};


#endif //PROJECT_PARTICLE_H
