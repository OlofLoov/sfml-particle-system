#include "ParticleVelocityUpdater.hpp"

ParticleVelocityUpdater::ParticleVelocityUpdater(ParticleEmitterSettings& emitterSettings, sf::Vector2u screenSize) : _emitterSettings(emitterSettings) {
    m_screenSize = screenSize;
}

void ParticleVelocityUpdater::update(Particle &p, sf::Vector2f mousePos, float deltaTime) {
    if(_emitterSettings.mouseAttracts) {
        sf::Vector2f &particlePosition = p.position;
        sf::Vector2f acc = mousePos - particlePosition;
        acc /= sqrt(acc.x * acc.x + acc.y * acc.y);

        sf::Vector2f &velocity = p.velocity;
        velocity += acc * (_emitterSettings.mouseAttractStrength * deltaTime);
        velocity -= 0.005f * velocity;
        particlePosition += velocity * deltaTime;
    } else {
        auto v = p.velocity * deltaTime;
        p.position += v;
    }

    // bounce "walls"
    auto futurePos = p.position + p.velocity * deltaTime;
    if (futurePos.x > m_screenSize.x || futurePos.x < 0)
        p.velocity = sf::Vector2f(-p.velocity.x, p.velocity.y);

    if (futurePos.y > m_screenSize.y || futurePos.y < 0)
        p.velocity = sf::Vector2f(p.velocity.x, -p.velocity.y);

}