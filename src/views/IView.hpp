#pragma once

#include <SFML/Graphics.hpp>

class IView
{
public:
    virtual ~IView(){};
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;
    virtual void initialize() = 0;
    virtual void onEvent(sf::Event event) = 0;
};
