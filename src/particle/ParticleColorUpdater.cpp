#include "ParticleColorUpdater.hpp"

void ParticleColorUpdater::update(Particle &p, sf::Vector2f mousePos, float deltaTime) {
    auto ratio = (p.lifeTime - p.lifeRemaining) / p.lifeTime;
    auto invRatio = 1 - ratio;

    p.vertex.color = sf::Color(
        p.startColor.r * (invRatio) + (ratio)*p.endColor.r,
        p.startColor.g * (invRatio) + (ratio)*p.endColor.g,
        p.startColor.b * (invRatio) + (ratio)*p.endColor.b,
        p.startColor.a * (invRatio) + (ratio)*p.endColor.a);
}