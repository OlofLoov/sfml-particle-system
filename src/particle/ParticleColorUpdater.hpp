#pragma once

#include "IParticleUpdater.hpp"

class ParticleColorUpdater: public IParticleUpdater {
public:
    void update(Particle &p, sf::Vector2f mousePos, float deltaTime);

    ~ParticleColorUpdater() {};
};
