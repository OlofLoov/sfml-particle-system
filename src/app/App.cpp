#include "App.hpp"
#include <iostream>
#include <math.h>
#include <random>
#include "Random.hpp"

App::App()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8.0;

    _window.create(sf::VideoMode(1600, 1200), "Particles", sf::Style::Titlebar, settings);
    _window.setFramerateLimit(60);
    _window.setVerticalSyncEnabled(false);
    m_scenes.push(std::make_unique<ParticleSystemView>(_window));
    ImGui::SFML::Init(_window);
}

void App::run()
{
    while (_window.isOpen())
    {
        update();
        render();
    }
}

void App::update()
{
    sf::Event event;
    m_dt = m_clock.restart().asSeconds();

    while (_window.pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            _window.close();
        }

        if (!this->m_scenes.empty())
            m_scenes.top()->onEvent(event);
    }

    if (!this->m_scenes.empty())
        m_scenes.top()->update(m_dt);
}

void App::render()
{
    _window.clear();
    if (!this->m_scenes.empty())
        m_scenes.top()->render();
    _window.display();
}
