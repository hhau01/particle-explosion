#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace particles {

class Swarm {
public:
    const static int NPARTICLES = 2000;

private:
    Particle * m_pParticles;
public:
    Swarm();
    virtual ~Swarm();
    void update();

    const Particle * const getParticles() { return m_pParticles; }
    
};

} // end namespace particles

#endif