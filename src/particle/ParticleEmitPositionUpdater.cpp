#include "ParticleEmitPositionUpdater.hpp"

ParticleEmitPositionUpdater::ParticleEmitPositionUpdater(ParticleEmitterSettings& emitterSettings) : _emitterSettings(emitterSettings) {
}

void ParticleEmitPositionUpdater::update(Particle &p, sf::Vector2f mousePos, float deltaTime) {
    if (_emitterSettings.emitAtMouse) {
        _emitterSettings.emitPos[0] = mousePos.x;
        _emitterSettings.emitPos[1] = mousePos.y;
    }
}