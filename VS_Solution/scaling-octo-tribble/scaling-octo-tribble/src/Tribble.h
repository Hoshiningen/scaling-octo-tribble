#pragma once
#include<SFML/Graphics.hpp>

class Tribble : public sf::Sprite
{
public:
	Tribble();
	virtual ~Tribble();

public:
	void tick(float deltaTime);

private:
	sf::Vector2f velocity;

};

