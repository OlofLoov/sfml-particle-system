#pragma once

#include "IParticleUpdater.hpp"

class ParticleEmitPositionUpdater: public IParticleUpdater {
public:
    ParticleEmitPositionUpdater(ParticleEmitterSettings& emitterSettings);
    void update(Particle &p, sf::Vector2f mousePos, float deltaTime);

    ~ParticleEmitPositionUpdater() {};

    ParticleEmitterSettings& _emitterSettings;
};
