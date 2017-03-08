#include "Swarm.h"
#include <stdlib.h>

namespace particles{

Swarm::Swarm() {
    m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
    delete [] m_pParticles;
}

void Swarm::update() {
    // loop through all particles
    for (int i = 0; i < Swarm::NPARTICLES; i++) {
        m_pParticles[i].update();
    }
}

} // end namespace particles

