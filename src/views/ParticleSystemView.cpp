#include "ParticleSystemView.hpp"
#include <math.h>
#include <iostream>
#include "Random.hpp"

ParticleSystemView::ParticleSystemView(sf::RenderWindow &window) : _window(window),
                                                                     m_particleEmitter(window.getSize()),
                                                                     m_ui(m_emitterSettings, window, m_particleEmitter)
{
    initialize();
}

void ParticleSystemView::initialize()
{
    /*if (!m_shader.loadFromFile("./res/shaders/basic.shader", sf::Shader::Fragment))
    {
        std::cerr << "Couldn't load fragment shader\n";
    }
    m_shader.setUniform("u_resolution", sf::Glsl::Vec2{_window.getSize()}); */

    m_emitterSettings.emitPos[0] = _window.getSize().x / 2;
    m_emitterSettings.emitPos[1] = _window.getSize().y / 2;

    Random::init();
}

void ParticleSystemView::onEvent(sf::Event event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        m_particleEmitter.clear();
    }
}

void ParticleSystemView::update(float deltaTime)
{
    auto mousePos = sf::Mouse::getPosition(_window);
    m_particleEmitter.update(deltaTime, sf::Vector2f(mousePos.x, mousePos.y));
    m_ui.update(deltaTime);
}

void ParticleSystemView::render()
{
    auto shape = sf::RectangleShape{sf::Vector2f{_window.getSize()}};
    if (m_particleEmitter.m_activeVertices.size() > 0)
    {
        _window.draw(
            &m_particleEmitter.m_activeVertices[0],
            m_particleEmitter.m_activeVertices.size(),
            sf::Points,
            sf::BlendAdd);
    }

    m_ui.render();
}
