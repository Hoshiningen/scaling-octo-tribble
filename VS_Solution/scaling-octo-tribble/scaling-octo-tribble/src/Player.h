#pragma once
#include<SFML/Graphics.hpp>

class Player : public sf::Sprite
{
public:
    explicit Player(sf::Vector2f origin);

    // We don't want no copying yo
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    Player(const Player&&) = delete;
    Player& operator=(const Player&&) = delete;

    virtual ~Player() = default;

    void tick(float deltaTime);

private:
    float speed{1000};
    sf::Vector2f origin{};
};