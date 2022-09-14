#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

// actual particle live on screen
struct Particle
{
    sf::Vector2f position;
    sf::Vector2f velocity;
    float rotation;
    float sizeBegin;
    float lifeTime;
    float lifeRemaining;
    bool active = false;
    sf::Vertex vertex;
    sf::Color startColor;
    sf::Color endColor;
};
