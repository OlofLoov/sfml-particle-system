#include "ParticleEmitter.hpp"
#include <iostream>
#include <math.h>
#include "Random.hpp"

ParticleEmitter::ParticleEmitter(sf::Vector2u screenSize)
{
    m_particlePool.resize(1000000);
    m_poolIndex = 0;
    m_screenSize = screenSize;

    m_particleUpdaters.push_back(std::make_unique<ParticleColorUpdater>());
    m_particleUpdaters.push_back(std::make_unique<ParticleVelocityUpdater>(m_emitProperties, m_screenSize));
    m_particleUpdaters.push_back(std::make_unique<ParticleEmitPositionUpdater>(m_emitProperties));
}

void ParticleEmitter::clear()
{
    for (auto &p : m_particlePool)
    {
        p.active = false;
        p.lifeRemaining = 0.0f;
    }

    m_poolIndex = 0;
    m_activeVertices.clear();
    m_emitProperties.continously = false;
}

void ParticleEmitter::updateSettings(const ParticleEmitterSettings &emitProperties)
{
    m_emitProperties = emitProperties;
}

void ParticleEmitter::emit(const ParticleEmitterSettings &emitProperties)
{
    m_emitProperties = emitProperties;
    emit();
}

void ParticleEmitter::emit()
{
    for (int i = 0; i < m_emitProperties.emitCount; i++)
    {
        float r = Random::randomFloat();
        float angleDegree = r * (m_emitProperties.angle[1] - m_emitProperties.angle[0]);
        float angleRad = (angleDegree * 3.14159f / 180.f);
        float angle = angleRad + (m_emitProperties.angleOffset * 3.14159 / 180.f);

        auto &particle = m_particlePool[m_poolIndex];
        particle.active = true;
        particle.position = sf::Vector2f(m_emitProperties.emitPos[0], m_emitProperties.emitPos[1]);

        float lifeRand = m_emitProperties.varyLifeDuration ? 
            Random::randomFloat() * m_emitProperties.lifeVariation : 1.0f;

        float velocityRand = m_emitProperties.varySpeed ? 
            Random::randomFloat() * m_emitProperties.speedVariation : 1.0f;

        particle.velocity = sf::Vector2f(
            100.f * cos(angle) * m_emitProperties.velocity[0] * velocityRand, 
            100.f * sin(angle) * m_emitProperties.velocity[1] * velocityRand);
        particle.lifeTime = m_emitProperties.lifeTime * lifeRand;

        particle.vertex.color = sf::Color(
            m_emitProperties.colorBegin[0] * 255,
            m_emitProperties.colorBegin[1] * 255,
            m_emitProperties.colorBegin[2] * 255,
            m_emitProperties.colorBegin[3] * 255);

        particle.startColor = sf::Color(
            m_emitProperties.colorBegin[0] * 255, 
            m_emitProperties.colorBegin[1] * 255, 
            m_emitProperties.colorBegin[2] * 255, 
            m_emitProperties.colorBegin[3] * 255);

        particle.endColor = sf::Color(
            m_emitProperties.colorEnd[0] * 255, 
            m_emitProperties.colorEnd[1] * 255, 
            m_emitProperties.colorEnd[2] * 255, 
            m_emitProperties.colorEnd[3] * 255);

        particle.vertex.position = particle.position;
        particle.lifeRemaining = particle.lifeTime;

        m_poolIndex += 1;
        if (m_poolIndex >= m_particlePool.size())
        {
            m_poolIndex = 0;
        }
    }
}

void ParticleEmitter::update(float deltaTime, sf::Vector2f mousePos)
{
    m_activeVertices.clear();
    for (auto &particle : m_particlePool)
    {
        if (!isParticleActive(particle))
            continue;

        m_activeVertices.push_back(particle.vertex);

        for(auto& updater : m_particleUpdaters)
            updater->update(particle, mousePos, deltaTime);
    
        particle.vertex.position = particle.position;
        particle.lifeRemaining -= deltaTime;
    }

    if (m_emitProperties.continously)
    {
        emit();
        if (m_emitProperties.angleOffsetOverTime)
            m_emitProperties.angleOffset += m_emitProperties.angleOffsetIncrement;

        if (m_emitProperties.emitVariationOverTime)
        {
            if (m_emitProperties.emitCount + m_emitProperties.emitVariationStepSize > m_emitProperties.emitVariationMaxCount)
                m_emitProperties.emitCount = m_emitProperties.emitVariationStepSize;
            else
                m_emitProperties.emitCount += m_emitProperties.emitVariationStepSize;
        }
    }
}

bool ParticleEmitter::isParticleActive(Particle &p)
{
    if (!p.active)
        return false;

    if (p.lifeRemaining <= 0.0f)
    {
        p.active = false;
        return false;
    }

    return true;
}
