#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particles {

struct Particle {
    double m_x;
    double m_y;

    double m_speed;
    double m_direction;

public:
    Particle();
    virtual ~Particle();

    void update();
};

} // end namespace particles

#endif