#pragma once

#include "ParticleProperties.hpp"
#include "ParticleEmitterSettings.hpp"

class IParticleUpdater {
public:
    virtual ~IParticleUpdater(){};
    virtual void update(Particle &p, sf::Vector2f mousePos, float deltaTime) = 0;
};