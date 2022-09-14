#pragma once

#include "IParticleUpdater.hpp"

class ParticleVelocityUpdater: public IParticleUpdater {
public:
    ParticleVelocityUpdater(ParticleEmitterSettings& emitterSettings, sf::Vector2u screenSize);
    void update(Particle &p, sf::Vector2f mousePos, float deltaTime);

    ~ParticleVelocityUpdater() {};

    ParticleEmitterSettings& _emitterSettings;
    sf::Vector2u m_screenSize;

};
