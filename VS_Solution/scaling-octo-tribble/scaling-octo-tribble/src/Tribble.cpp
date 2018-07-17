#include "Tribble.h"
#include "SFML\System\Vector2.hpp"




Tribble::Tribble() :
	velocity(0.f, 400.0f)
{

}



Tribble::~Tribble()
{
}

void Tribble::tick(float deltaTime)
{
	//get position
	//auto & position = this->getPosition();
	sf::Vector2f position = this->getPosition();

	//change it by velocity
	position += { deltaTime * velocity.x, deltaTime * velocity.y};

	//update sprite's position based on how velocity moved it
	setPosition(position);
	
}
