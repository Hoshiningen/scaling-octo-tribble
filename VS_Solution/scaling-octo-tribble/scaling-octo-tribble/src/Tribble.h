#pragma once

#include<SFML/Graphics.hpp>

#include "GameConstants.h"

BEGIN_GAME_NAMESPACE

class Tribble : public sf::Sprite
{
public:

	Tribble();
    Tribble(const Tribble&) = delete;
    Tribble& operator=(const Tribble&) = delete;

	virtual ~Tribble();

	void tick(const float deltaTime);
    void setVelocity(const sf::Vector2f& velocity);

private:

    sf::Vector2f velocity{};
};

END_GAME_NAMESPACE
