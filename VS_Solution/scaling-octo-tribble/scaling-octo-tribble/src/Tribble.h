#pragma once
#include<SFML/Graphics.hpp>

class Tribble : public sf::Sprite
{
public:
	Tribble();
    Tribble(const Tribble&) = delete;
    Tribble& operator=(const Tribble&) = delete;

	virtual ~Tribble();

	void tick(float deltaTime);
    void setVelocity(const sf::Vector2f& velocity);

private:
    sf::Vector2f velocity{};
};

