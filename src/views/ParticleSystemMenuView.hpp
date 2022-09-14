#pragma once
#include "ParticleEmitter.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>
#include "WidgetHelper.hpp"

class ParticleSystemMenuView
{
public:
    ParticleSystemMenuView(ParticleEmitterSettings &emitterSettings, sf::RenderWindow &window, ParticleEmitter &particleEmitter);

    void update(float deltaTime);
    void render();

private:
    sf::Clock m_deltaClock;
    ParticleEmitter &_particleEmitter;
    ParticleEmitterSettings &_emitterSettings;
    sf::RenderWindow &_window;
    WidgetHelper m_widgetHelper;
};
