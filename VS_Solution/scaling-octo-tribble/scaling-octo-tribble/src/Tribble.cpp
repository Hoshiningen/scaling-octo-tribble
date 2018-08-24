#include "Tribble.h"

#include "SFML\System\Vector2.hpp"

sot::Tribble::Tribble() 
    : velocity(0.f, 400.0f)
{}

sot::Tribble::~Tribble() = default;

void sot::Tribble::tick(const float deltaTime)
{
	//get position
	sf::Vector2f position = getPosition();

	//change it by velocity
	position += { deltaTime * velocity.x, deltaTime * velocity.y};

	//update sprite's position based on how velocity moved it
	setPosition(position);
}

void sot::Tribble::setVelocity(const sf::Vector2f& v)
{
    velocity = v;
}
