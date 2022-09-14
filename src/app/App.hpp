#pragma once
#include <SFML/Graphics.hpp>
#include "Views.hpp"
#include "IView.hpp"
#include <memory>
#include <stack>

class App
{
public:
    App();
    ~App()
    {
        std::cout << "Destroying Game" << std::endl;
    };

    void run();

private:
    void render();
    void update();

    float m_dt;
    sf::Clock m_clock;
    sf::RenderWindow _window;
    std::stack<std::unique_ptr<IView>> m_scenes;
};
