#include "Swarm.h"
#include <stdlib.h>

namespace particles{

Swarm::Swarm() {
    m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
    delete [] m_pParticles;
}

} // end namespace particles



