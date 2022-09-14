#pragma once

#include "IView.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ParticleProperties.hpp"
#include "ParticleEmitter.hpp"
#include "ParticleSystemMenuView.hpp"

class ParticleSystemView : public IView
{
public:
    ParticleSystemView(sf::RenderWindow &window);
    ~ParticleSystemView()
    {
        std::cout << "Destorying ParticleSystemScene" << std::endl;
    };

    void update(float deltaTime);
    void render();
    void initialize();
    void onEvent(sf::Event event);

private:
    sf::RenderWindow &_window;
    ParticleEmitter m_particleEmitter;
    sf::Shader m_shader;
    ParticleEmitterSettings m_emitterSettings;
    ParticleSystemMenuView m_ui;
};