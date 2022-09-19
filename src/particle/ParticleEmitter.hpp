#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "ParticleProperties.hpp"
#include <iostream>
#include "ParticleEmitterSettings.hpp"
#include "ParticleColorUpdater.hpp"
#include "ParticleEmitPositionUpdater.hpp"
#include "ParticleVelocityUpdater.hpp"

#include "IParticleUpdater.hpp"
#include <memory>

class ParticleEmitter
{
public:
    ParticleEmitter(sf::Vector2u screenSize);
    ~ParticleEmitter() {
        std::cout << "Destroying particle emitter" << std::endl;
    }
    void update(float deltaTime, sf::Vector2f mousePos);
    void emit(const ParticleEmitterSettings &emitProperties);
    void clear();
    std::vector<sf::Vertex> m_activeVertices;
    void updateSettings(const ParticleEmitterSettings &emitProperties);

private:
    void emit();
    bool isParticleActive(Particle& particle);

    std::vector<Particle> m_particlePool;
    uint32_t m_poolIndex = 0;
    ParticleEmitterSettings m_emitProperties;
    sf::Vector2u m_screenSize;

    std::vector<std::unique_ptr<IParticleUpdater>> m_particleUpdaters;
};